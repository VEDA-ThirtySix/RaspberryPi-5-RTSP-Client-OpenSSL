#include "dialog_videoclip.h"
#include "ui_clip.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QLabel>
#include <QDateTime>
#include <QHostAddress>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <srtp2/srtp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <QElapsedTimer>

#define BUFFER_SIZE 65535

// static constexpr uint8_t NALU_NRI_MASK = 0x60;
static constexpr uint8_t NALU_F_NRI_MASK = 0xe0;
static constexpr uint8_t NALU_TYPE_MASK = 0x1F;

static constexpr uint8_t FU_S_MASK = 0x80;
static constexpr uint8_t FU_E_MASK = 0x40;
// static constexpr uint8_t SET_FU_A_MASK = 0x1C;

// 전역 변수 추가
uint16_t last_sequence_number = 0;
bool first_packet = true;
// std::ofstream h264_file;
QFile h264_file;
std::vector<uint8_t> naluBuffer;
bool isReceivingNALU = false;
volatile bool running = true;
size_t expectedNaluSize = 0;  // 예상되는 NALU 크기 추가
std::map<uint16_t, std::vector<uint8_t>> fragmentBuffer;  // 시퀀스 번호별 프래그먼트 저장
uint16_t expectedSeqNum = 0;
bool waitingForStart = true;
bool isFirstPacket = true;

VideoClipDialog::VideoClipDialog(const QString &host, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VideoClipDialog)
    , ffmpegProcess(new QProcess(this))
    , frameTimer(new QTimer(this))
    , reconnectAttempts(0)
    , sslContext(nullptr)
    , sslSession(nullptr)
    , srtpSession(nullptr)
{
    ui->setupUi(this);
    setupConnections();
    setupSlider();

    h264File.setFileName("/Users/jinurung/VEDA/client/PAMS-36/Client/cctv_36/src/view/output.h264");

    // RTSP URL 설정
    m_rtspUrl = QString("%1://%2:%3/")
                    .arg(PROTOCOL, host, QString::number(CLIP_PORT));

    qDebug() << "QDEBUG(SW)$ Clip RTSP URL:" << m_rtspUrl;

    initializeOpenSSL();

    // FFmpeg 프레임 타이머 설정
    frameTimer->setInterval(33); // ~30fps
    connect(frameTimer, &QTimer::timeout, this, &VideoClipDialog::captureFrame);
    

}

void VideoClipDialog::setupConnections()
{
    // 컨트롤 버튼 연결
    connect(ui->playPauseButton, &QPushButton::clicked, this, &VideoClipDialog::playPauseVideo);
    connect(ui->stopButton, &QPushButton::clicked, this, &VideoClipDialog::stopVideo);
    // connect(udpSocket, &QUdpSocket::readyRead, this, &VideoClipDialog::processIncomingPackets);
}

void VideoClipDialog::cleanup() {
    if (sslSession) {
        SSL_free(sslSession);
        sslSession = nullptr;
    }
    if (sslContext) {
        SSL_CTX_free(sslContext);
        sslContext = nullptr;
    }
    if (srtpSession) {
        srtp_dealloc(srtpSession);
        srtpSession = nullptr;
    }
    if (rtpSockfd >= 0) {
        ::close(rtpSockfd);
        rtpSockfd = -1;
    }
    if (h264File.isOpen()) {
        h264File.close();
    }
}

SSL_CTX* VideoClipDialog::create_dtls_client_context() {
    const SSL_METHOD* method = DTLS_client_method();
    SSL_CTX* ctx = SSL_CTX_new(method);
    if (!ctx) {
        qDebug() << "Unable to create SSL context";
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    SSL_CTX_set_min_proto_version(ctx, DTLS1_2_VERSION);
    SSL_CTX_set_max_proto_version(ctx, DTLS1_2_VERSION);

    //SSL_CTX_set_info_callback(ctx, debug_callback);

    return ctx;
}

void VideoClipDialog::configure_context(SSL_CTX* ctx) {
    if (SSL_CTX_use_certificate_file(ctx, "/Users/jinurung/VEDA/client/PAMS-36/Client/cctv_36/src/view/client.crt", SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ctx, "/Users/jinurung/VEDA/client/PAMS-36/Client/cctv_36/src/view/client.key", SSL_FILETYPE_PEM) <= 0) {
        qDebug() << "Error configuring SSL context with certificate and key";
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    if (!SSL_CTX_load_verify_locations(ctx, "/Users/jinurung/VEDA/client/PAMS-36/Client/cctv_36/src/view/ca.crt", nullptr)) {
        qDebug() << "Error loading CA certificate to trust store";
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT, nullptr);
}

void VideoClipDialog::startStreaming()
{

    qDebug() << "startstreaming";

    if (h264File.exists()) {
        if (!h264File.remove()) {
            qDebug() << "Failed to remove existing H264 file.";
            return;
        }
        qDebug() << "Existing H264 file removed.";
    }

    // H.264 파일 초기화
    if (!h264File.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open H264 file for writing.";
        return;
    }
    h264File.close(); // 스트리밍 시작 전에 파일을 닫고, 이후 handleNALU에서 다시 열림

    if (!startRTSPSession() || !setupDTLSAndSRTP()) {
        qDebug() << "Failed to start streaming.";
        return;
    }

    // 스레드 직접 생성
    receiverThread = new QThread(this); // this를 부모로 설정해 소유권 명확히 설정
    QObject::connect(receiverThread, &QThread::finished, receiverThread, &QObject::deleteLater);

    // 스레드에서 실행할 작업 생성
    QObject::connect(receiverThread, &QThread::started, this, [this]() {
        this->receiveRTPPackets(); // 스레드에서 수신 함수 실행
    });

    receiverThread->start(); // 스레드 시작
    qDebug() << "Receiver thread started.";

}

bool VideoClipDialog::startRTSPSession()
{
    // QTcpSocket으로 RTSP 요청 처리
    QTcpSocket rtspSocket;
    rtspSocket.connectToHost("192.168.35.11", 7554);
    if (!rtspSocket.waitForConnected()) {
        qDebug() << "RTSP connection failed";
        return false;
    }

    QString setupRequest = "SETUP rtsp://127.0.0.1:7554/test/track1 RTSP/1.0\r\nCSeq: 3\r\nTransport: RTP/AVP;unicast;client_port=54325-54326\r\n\r\n";
    rtspSocket.write(setupRequest.toUtf8());
    rtspSocket.waitForBytesWritten();
    rtspSocket.waitForReadyRead();
    qDebug() << "SETUP Response:" << rtspSocket.readAll();


    QString playRequest = "PLAY rtsp://127.0.0.1:8554/test RTSP/1.0\r\nCSeq: 4\r\nSession: 12345678\r\n\r\n";
    rtspSocket.write(playRequest.toUtf8());
    rtspSocket.waitForBytesWritten();
    rtspSocket.waitForReadyRead();
    qDebug() << "PLAY Response:" << rtspSocket.readAll();

    rtspSocket.close();
    return true;
}

bool VideoClipDialog::setupDTLSAndSRTP()
{

    rtpSockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (rtpSockfd < 0) {
        perror("RTP socket creation failed");
        return -1;
    }


    // 클라이언트 주소 바인딩
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    client_addr.sin_port = htons(54325);

    if (bind(rtpSockfd, (struct sockaddr*)&client_addr, sizeof(client_addr)) < 0) {
        perror("Client bind failed");
    }
    qDebug() << "Client is bound to port " << ntohs(client_addr.sin_port);



    struct sockaddr_in rtp_addr;
    memset(&rtp_addr, 0, sizeof(rtp_addr));
    rtp_addr.sin_family = AF_INET;
    rtp_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "192.168.35.11", &rtp_addr.sin_addr);


    if (::connect(rtpSockfd, (struct sockaddr*)&rtp_addr, sizeof(rtp_addr)) < 0) {
        perror("RTP server connection failed");
        return -1;
    } else {
        qDebug() << "Connected to RTP server on port " << ntohs(rtp_addr.sin_port);
    }


    SSL_CTX* ctx = create_dtls_client_context();

    const char* srtp_profiles = "SRTP_AES128_CM_SHA1_80";
    if (SSL_CTX_set_tlsext_use_srtp(ctx, srtp_profiles) != 0) {
        qDebug() << "Error setting SRTP profiles";
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        return -1;
    }


    configure_context(ctx);

    BIO* bio = BIO_new_dgram(rtpSockfd, BIO_NOCLOSE);
    if (!bio) {
        qDebug() << "Failed to create BIO";
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        return -1;
    }


    if (BIO_ctrl(bio, BIO_CTRL_DGRAM_SET_CONNECTED, 0, &rtp_addr) <= 0) {
        qDebug() << "Failed to set connected BIO for server";
        ERR_print_errors_fp(stderr);
        BIO_free(bio);
        SSL_CTX_free(ctx);
        return -1;
    } else {
        qDebug() << "BIO_CTRL_DGRAM_SET_CONNECTED set for server address: "
                  << inet_ntoa(rtp_addr.sin_addr) << ":" << ntohs(rtp_addr.sin_port);
    }


    SSL* ssl = SSL_new(ctx);
    if (!ssl) {
        qDebug() << "Unable to create SSL structure";
        ERR_print_errors_fp(stderr);
        BIO_free(bio);
        SSL_CTX_free(ctx);
        return -1;
    }

    SSL_set_bio(ssl, bio, bio);

    // DTLS 핸드셰이크 수행
    int handshakeResult = SSL_connect(ssl);
    if (handshakeResult <= 0) {
        int sslError = SSL_get_error(sslSession, handshakeResult);
        qDebug() << "DTLS handshake failed with error code:" << sslError;
        switch (sslError) {
        case SSL_ERROR_NONE:
            qDebug() << "No error occurred." ;
            break;
        case SSL_ERROR_ZERO_RETURN:
            qDebug() << "The TLS/SSL connection has been ::closed." ;
            break;
        case SSL_ERROR_WANT_READ:
        case SSL_ERROR_WANT_WRITE:
            qDebug() << "The operation did not complete and should be retried." ;
            break;
        case SSL_ERROR_SYSCALL:
            qDebug() << "A system call error occurred." ;
            perror("System call error");
            qDebug() << "errno: " << errno << " (" << strerror(errno) << ")" ;
            break;
        case SSL_ERROR_SSL:
            qDebug() << "A failure in the SSL library occurred, usually a protocol error." ;
            ERR_print_errors_fp(stderr);
            break;
        default:
            qDebug() << "An unknown error occurred." ;
            break;
        }
        ERR_print_errors_fp(stderr);
        return false;
    }

    qDebug() << "DTLS handshake successful";

    const char* cipher_suite = SSL_get_cipher(ssl);
    qDebug() << "Negotiated Cipher Suite: " << cipher_suite ;


    const SRTP_PROTECTION_PROFILE *profile = SSL_get_selected_srtp_profile(ssl);
    if (profile != nullptr) {
        qDebug() << "Selected SRTP profile: " << profile->name ;
    } else {
        qDebug() << "Failed to negotiate SRTP profile" ;
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        ::close(rtpSockfd);
        return -1;
    }


    unsigned char srtp_key[SRTP_MASTER_KEY_LEN];
    if (SSL_export_keying_material(ssl, srtp_key, SRTP_MASTER_KEY_LEN, "EXTRACTOR-dtls_srtp", strlen("EXTRACTOR-dtls_srtp"), nullptr, 0, 0) != 1) {
        qDebug() << "Failed to export keying material for SRTP" ;
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        ::close(rtpSockfd);
        return -1;
    }

    // 디버그 로그 추가
    QString srtpKeyString;
    for (int i = 0; i < SRTP_MASTER_KEY_LEN; ++i) {
        srtpKeyString.append(QString("%1 ").arg(srtp_key[i], 2, 16, QChar('0')).toUpper());
    }
    qDebug() << "Exported SRTP key:" << srtpKeyString;


    if (srtp_init() != srtp_err_status_ok) {
        qDebug() << "Failed to initialize SRTP library." ;
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        ::close(rtpSockfd);
        return -1;
    }

    srtp_policy_t policy;
    memset(&policy, 0, sizeof(srtp_policy_t));
    srtp_crypto_policy_set_aes_cm_128_hmac_sha1_80(&policy.rtp);
    srtp_crypto_policy_set_aes_cm_128_hmac_sha1_80(&policy.rtcp);
    policy.ssrc.type = ssrc_any_inbound;
    policy.ssrc.value = 20001102;
    policy.key = srtp_key;
    policy.next = nullptr;

    if (srtp_create(&srtpSession, &policy) != srtp_err_status_ok) {
        qDebug() << "Failed to create SRTP session" ;
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        ::close(rtpSockfd);
        return -1;
    }

    qDebug() << "End setup";

    return true;
}

void VideoClipDialog::receiveRTPPackets() {
    qDebug() << "start receivePacket";
    running = true;

    unsigned char buffer[BUFFER_SIZE];
    QElapsedTimer lastPacketTimer;
    lastPacketTimer.start();

    const int timeoutThreshold = 3000;

    while (!QThread::currentThread()->isInterruptionRequested() && running) {
        struct timeval tv;
        tv.tv_sec = 5; // recv 타임아웃 설정 (5초)
        tv.tv_usec = 0;
        setsockopt(rtpSockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

        int len = recv(rtpSockfd, buffer, sizeof(buffer), 0);

        if (len < 0) {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                // recv가 타임아웃 되었을 경우, 타이머를 확인
                if (lastPacketTimer.elapsed() > timeoutThreshold) {
                    qDebug() << "No RTP packets received for 3 seconds. Stopping reception.";
                    break;
                }
                continue;
            } else if (errno == EINTR) {
                // 인터럽트 처리
                continue;
            } else {
                perror("Error while receiving RTP packets");
                break;
            }
        }

        lastPacketTimer.restart();

        int packetLen = len;
        srtp_err_status_t status = srtp_unprotect(srtpSession, buffer, &packetLen);
        if (status != srtp_err_status_ok) {
            qDebug() << "SRTP unprotect failed, status:" << status;
            continue;
        }

        if (packetLen <= 12) {  // RTP 헤더 크기보다 작다면 잘못된 패킷
            qDebug() << "Packet length too small after SRTP unprotect:" << packetLen;
            continue;
        }
        RTPHeader header;
        parseRTPHeader(buffer, header);

        const uint8_t *rtpPayload = buffer + 12;
        size_t payloadSize = packetLen - 12;
        processRTPPacket(rtpPayload, payloadSize, header.sequence_number);


    }
    // 수신 종료 시 남아 있는 데이터를 저장
    if (!naluBuffer.empty()) {
        qDebug() << "Flushing remaining NALU buffer to file.";
        handleCompleteNALU(naluBuffer.data(), naluBuffer.size());
        naluBuffer.clear();
    }
    qDebug() << "receiveRTPPackets loop exiting.";
    stopStreaming();
}

void VideoClipDialog::stopStreaming() {
    running = false;

    if (receiverThread) {
        if (receiverThread->isRunning()) {
            qDebug() << "Requesting receiverThread to stop...";
            receiverThread->requestInterruption(); // 종료 요청
            receiverThread->quit();               // 이벤트 루프 종료
            if (!receiverThread->wait(5000)) {    // 최대 5초 대기
                qDebug() << "Force terminating receiverThread...";
                receiverThread->terminate();
                receiverThread->wait();
            }
        }

        receiverThread = nullptr;
        qDebug() << "receiverThread safely deleted.";
    }

    cleanup();
    qDebug() << "Streaming stopped and resources cleaned up.";

    // 스트리밍 종료 후 H.264 파일 재생
    playH264File();
}





void VideoClipDialog::handleCompleteNALU(const uint8_t* naluData, size_t naluSize) {
    QByteArray nalu(reinterpret_cast<const char *>(naluData), naluSize);

    if (nalu.isEmpty()) {
        qDebug() << "Empty NALU received, skipping.";
        return;
    }

    if (!h264File.isOpen()) {
        if (!h264File.open(QIODevice::WriteOnly | QIODevice::Append)) {
            qDebug() << "Failed to open H264 file for writing.";
            return;
        }
    }

    const uint8_t start_code[4] = {0x00, 0x00, 0x00, 0x01};
    h264File.write(reinterpret_cast<const char*>(start_code), 4);  // Start Code 추가
    h264File.write(nalu);
    h264File.flush();

    qDebug() << "Wrote NALU of size:" << nalu.size();
}


// RTP 헤더 파싱 함수 추가
bool VideoClipDialog::parseRTPHeader(const uint8_t* buffer, RTPHeader& header) {
    // RTP 헤더 버전 체크
    header.version = (buffer[0] >> 6) & 0x03;
    if (header.version != 2) {
        qDebug() << "Invalid RTP version" ;
        return false;
    }

    header.padding = (buffer[0] >> 5) & 0x01;
    header.extension = (buffer[0] >> 4) & 0x01;
    header.csrc_count = buffer[0] & 0x0F;
    header.marker = (buffer[1] >> 7) & 0x01;
    header.payload_type = buffer[1] & 0x7F;

    header.sequence_number = ntohs(*reinterpret_cast<const uint16_t*>(buffer + 2));
    header.timestamp = ntohl(*reinterpret_cast<const uint32_t*>(buffer + 4));
    header.ssrc = ntohl(*reinterpret_cast<const uint32_t*>(buffer + 8));

    return true;
}

// RTP 페이로드 처리 함수
void VideoClipDialog::processRTPPacket(const uint8_t* rtpPayload, size_t payloadSize, uint16_t seqNum) {
    if (payloadSize < 2) return;

    const uint8_t fuIndicator = rtpPayload[0];
    const uint8_t naluType = fuIndicator & NALU_TYPE_MASK;

    if (naluType == 28) {  // FU-A
        const uint8_t fuHeader = rtpPayload[1];
        const bool isStart = fuHeader & FU_S_MASK;
        const bool isEnd = fuHeader & FU_E_MASK;
        const uint8_t originalNaluType = fuHeader & NALU_TYPE_MASK;

        if (isStart) {
            naluBuffer.clear();
            const uint8_t reconstructedNaluHeader = (fuIndicator & NALU_F_NRI_MASK) | originalNaluType;
            naluBuffer.push_back(reconstructedNaluHeader);
            naluBuffer.insert(naluBuffer.end(), rtpPayload + 2, rtpPayload + payloadSize);
        } else if (!naluBuffer.empty()) {
            naluBuffer.insert(naluBuffer.end(), rtpPayload + 2, rtpPayload + payloadSize);
            if (isEnd) {
                handleCompleteNALU(naluBuffer.data(), naluBuffer.size());
                naluBuffer.clear();
            }
        }
    } else {
        // 단일 NALU
        handleCompleteNALU(rtpPayload, payloadSize);
    }
}

void VideoClipDialog::playH264File() {
    qDebug() << "start playh264";
    if (ffmpegProcess->state() == QProcess::Running) {
        qDebug() << "FFmpeg is already running!";
        return;
    }

#ifdef Q_OS_MAC
    QString ffmpegPath = "/opt/homebrew/bin/ffmpeg";
#elif defined(Q_OS_LINUX)
    QString ffmpegPath = "/usr/bin/ffmpeg";
#endif

    // QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    // env.insert("PATH", "/opt/homebrew/bin");
    // env.insert("DYLD_LIBRARY_PATH", "/opt/homebrew/lib");
    // ffmpegProcess->setProcessEnvironment(env);


    QString h264FilePath = QFileInfo(h264File).absoluteFilePath();
    if (!QFile::exists(h264FilePath) || QFileInfo(h264FilePath).size() == 0) {
        qDebug() << "H.264 file does not exist or is empty: " << h264FilePath;
        showErrorMessage("H.264 file is invalid or empty: " + h264FilePath);
        return;
    }

    QStringList arguments = {
        "-re",
        "-i", h264FilePath,
        "-pix_fmt", "rgb24",
        "-vf", "fps=30",
        "-s", "800x600",
        "-f", "rawvideo",
        "-loglevel", "debug",
        "-"
    };

    connect(ffmpegProcess, &QProcess::readyReadStandardOutput, this, &VideoClipDialog::captureFrame);
    // connect(ffmpegProcess, &QProcess::readyReadStandardError, this, [this]() {
    //     QByteArray errorData = ffmpegProcess->readAllStandardError();
    //     qDebug() << "FFmpeg error output: " << errorData;
    // });

    // FFmpeg 실행
    ffmpegProcess->start(ffmpegPath, arguments);
    if (!ffmpegProcess->waitForStarted()) {
        showErrorMessage("Failed to start FFmpeg");
        return;
    }

    qDebug() << "FFmpeg started with arguments:" << arguments;
}



void VideoClipDialog::initializeOpenSSL()
{
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
}

void VideoClipDialog::stopFFmpeg() {
    frameTimer->stop();

    if (ffmpegProcess->state() == QProcess::Running) {
        disconnect(ffmpegProcess, &QProcess::readyReadStandardOutput, this, &VideoClipDialog::captureFrame);
        ffmpegProcess->terminate();

        if (!ffmpegProcess->waitForFinished(3000)) {
            qDebug() << "Force killing FFmpeg process.";
            ffmpegProcess->kill();
            ffmpegProcess->waitForFinished();
        }
    }

    qDebug() << "FFmpeg stopped.";
}


void VideoClipDialog::captureFrame() {
    if (ffmpegProcess->state() != QProcess::Running) {
        qDebug() << "FFmpeg is not running, skipping captureFrame.";
        return;
    }

    QByteArray frameData = ffmpegProcess->readAllStandardOutput();
    if (frameData.isEmpty()) {
        qDebug() << "No frame data available.";
        return;
    }

    incompleteBuffer.append(frameData);

    const int width = 800;
    const int height = 600;
    const int frameSize = width * height * 3;

    while (incompleteBuffer.size() >= frameSize) {
        QByteArray singleFrameData = incompleteBuffer.left(frameSize);
        incompleteBuffer.remove(0, frameSize);

        QImage image((const uchar*)singleFrameData.data(), width, height, QImage::Format_RGB888);

        if (image.isNull()) {
            qDebug() << "Invalid frame data, skipping frame.";
            continue;
        }

        QPixmap pixmap = QPixmap::fromImage(image).scaled(ui->ffmpegLabel->size(),
                                                          Qt::KeepAspectRatioByExpanding,
                                                          Qt::SmoothTransformation);

        ui->ffmpegLabel->setPixmap(pixmap);

        qint64 currentTime = QDateTime::currentMSecsSinceEpoch() - startTime;
        updatePosition(currentTime);
    }

    qDebug() << "Remaining incomplete buffer size:" << incompleteBuffer.size();
}





// void VideoClipDialog::captureFrame() {
//     if (ffmpegProcess->state() != QProcess::Running) {
//         qDebug() << "FFmpeg is not running, skipping captureFrame.";
//         return;
//     }

//     QByteArray frameData = ffmpegProcess->readAllStandardOutput();
//     if (frameData.isEmpty()) {
//         qDebug() << "No frame data available.";
//         return;
//     }

//     const int width = 800;
//     const int height = 600;
//     const int frameSize = width * height * 3; // rgb24: 3 bytes per pixel

//     incompleteBuffer.append(frameData);

//     while (incompleteBuffer.size() >= frameSize) {
//         QByteArray singleFrameData = incompleteBuffer.left(frameSize);
//         incompleteBuffer.remove(0, frameSize);

//         QImage image((const uchar*)singleFrameData.data(),
//                      width, height, QImage::Format_RGB888);

//         QPixmap scaledPixmap = QPixmap::fromImage(image).scaled(
//             ui->ffmpegLabel->size(),
//             Qt::KeepAspectRatioByExpanding,
//             Qt::SmoothTransformation);

//         ui->ffmpegLabel->setPixmap(scaledPixmap);

//         qint64 currentTime = QDateTime::currentMSecsSinceEpoch() - startTime;
//         updatePosition(currentTime);
//     }

//     if (incompleteBuffer.size() > 0) {
//         qDebug() << "Remaining incomplete buffer size:" << incompleteBuffer.size();
//     }
// }



void VideoClipDialog::playPauseVideo()
{
    QString h264FilePath = "/Users/jinurung/VEDA/client/PAMS-36/Client/cctv_36/src/view/output.h264";

    // FFmpeg이 실행중이 아니면 시작
    if (ffmpegProcess->state() != QProcess::Running) {
        // startFFmpeg();
        startStreaming();
        frameTimer->start();
        ui->playPauseButton->setIcon(QIcon(":/images/pause.png"));
        return;
    }

    if (frameTimer->isActive()) {
        frameTimer->stop();
        ui->playPauseButton->setIcon(QIcon(":/images/play.png"));
    } else {
        frameTimer->start();
        ui->playPauseButton->setIcon(QIcon(":/images/pause.png"));
    }
}

void VideoClipDialog::stopVideo() {
    if (frameTimer->isActive()) {
        frameTimer->stop();
    }
    frameCount = 0;
    ui->playPauseButton->setIcon(QIcon(":/images/play.png"));
    ui->positionSlider->setValue(0);
    ui->currentTimeLabel->setText("00:00");
    stopFFmpeg();

    // 추가: 슬라이더를 초기 상태로
    ui->totalTimeLabel->setText("00:00");
}


void VideoClipDialog::updatePosition(qint64 position)
{
    if (!ui->positionSlider->isSliderDown()) {
        ui->positionSlider->setValue(position);
    }
    ui->currentTimeLabel->setText(formatTime(position));
}

QString VideoClipDialog::formatTime(qint64 milliseconds)
{
    int seconds = (milliseconds / 1000) % 60;
    int minutes = (milliseconds / 60000) % 60;
    return QString("%1:%2")
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'));
}

void VideoClipDialog::showErrorMessage(const QString &message)
{
    QMessageBox::critical(this, tr("Streaming Error"), message);
}

void VideoClipDialog::handleError()
{
    QString errorString = ffmpegProcess->errorString();
    qDebug() << "FFmpeg error:" << errorString;

    if (reconnectAttempts < MAX_RECONNECT_ATTEMPTS) {
        showErrorMessage(tr("Stream error: %1\nAttempting to reconnect...").arg(errorString));
        QTimer::singleShot(RECONNECT_INTERVAL, this, &VideoClipDialog::reconnectStream);
        reconnectAttempts++;
    } else {
        showErrorMessage(tr("Stream connection failed: %1\nMax reconnection attempts exceeded.").arg(errorString));
    }
}

void VideoClipDialog::setupSlider() {
    ui->totalTimeLabel->setText("00:15");
    const int CLIP_DURATION = 15000;
    ui->positionSlider->setRange(0, CLIP_DURATION);
    ui->positionSlider->setSingleStep(100);

    // 독립적인 타이머 제거하고 프레임 타이머와 연동
    // connect(ui->positionSlider, &QSlider::sliderMoved, this, [this](int position) {
    //     updatePosition(position);
    // });
    connect(ui->positionSlider, &QSlider::sliderMoved, this, [this](int position) {
        qint64 adjustedPosition = position;
        updatePosition(adjustedPosition);
    });

}

void VideoClipDialog::reconnectStream()
{
    stopFFmpeg();
    // startFFmpeg();
}

VideoClipDialog::~VideoClipDialog()
{
    stopStreaming();
    stopFFmpeg();

    delete ui;
    qDebug() << "VideoClipDialog safely destroyed.";
}

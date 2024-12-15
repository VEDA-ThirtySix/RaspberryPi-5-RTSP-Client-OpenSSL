#ifndef DIALOG_VIDEOCLIP_H
#define DIALOG_VIDEOCLIP_H

#include <QDialog>
#include <QProcess>
#include <QTimer>
#include <QUdpSocket>
#include <QThread>
#include <QSslSocket>
#include <openssl/ssl.h>
#include <srtp2/srtp.h>
#include <QFile>
#include <QElapsedTimer>
#include <QFileInfo>

struct RTPHeader {
    uint8_t version : 2;
    uint8_t padding : 1;
    uint8_t extension : 1;
    uint8_t csrc_count : 4;
    uint8_t marker : 1;
    uint8_t payload_type : 7;
    uint16_t sequence_number;
    uint32_t timestamp;
    uint32_t ssrc;
};

namespace Ui {
class VideoClipDialog;
}

class VideoClipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VideoClipDialog(const QString &host, QWidget *parent = nullptr);
    ~VideoClipDialog();

private slots:
    void handleError();
    void captureFrame();
    void playPauseVideo();
    void stopVideo();
    void updatePosition(qint64 position);
    void reconnectStream();

private:

    void setupConnections();
    // void startFFmpeg();
    void stopFFmpeg();
    void showErrorMessage(const QString &message);
    QString formatTime(qint64 milliseconds);
    void setupSlider();
    void stopStreaming();
    bool startRTSPSession();
    bool setupDTLSAndSRTP();
    void startStreaming();
    void playH264File();


    void initializeOpenSSL();
    SSL_CTX* create_dtls_client_context();
    void configure_context(SSL_CTX* ctx);

    void handleCompleteNALU(const uint8_t* naluData, size_t naluSize);
    bool parseRTPHeader(const uint8_t* buffer, RTPHeader& header);
    void processRTPPacket(const uint8_t* rtpPayload, size_t payloadSize, uint16_t seqNum);
    void cleanup();
    void receiveRTPPackets();


    Ui::VideoClipDialog *ui;
    QProcess *ffmpegProcess;
    QTimer *frameTimer;
    QString m_rtspUrl;
    int reconnectAttempts;
    QByteArray incompleteBuffer;
    qint64 frameCount = 0;
    qint64 startTime;
    QUdpSocket *udpSocket;
    QThread *receiverThread;
    bool running;
    int rtpSockfd;
    QFile h264File;


    SSL_CTX *sslContext;
    SSL *sslSession;
    srtp_t srtpSession;

    static constexpr const char *DTLS_SRTP_LABEL = "EXTRACTOR-dtls_srtp";
    static const int MAX_RECONNECT_ATTEMPTS = 3;
    static const int RECONNECT_INTERVAL = 5000;
    static constexpr const char* PROTOCOL = "rtsp";
    static const int CLIP_PORT = 7554;

    QElapsedTimer lastPacketTimer; // 마지막 RTP 패킷 수신 시간 기록
    static constexpr int PACKET_TIMEOUT_MS = 5000; // 타임아웃 (예: 5초)
};

#endif // DIALOG_VIDEOCLIP_H

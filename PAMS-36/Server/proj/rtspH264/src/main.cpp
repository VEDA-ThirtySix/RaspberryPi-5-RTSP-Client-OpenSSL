#include <rtsp.hpp>

#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    RTSP rtspServer(argv[1]);
    rtspServer.Start(20001102, "h264_streaming", 600, 30);

    return 0;
}

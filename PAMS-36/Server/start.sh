#!/bin/bash

# tfliteRuntime을 새로운 lxterm에서 실행
echo "Runnig tfliteRuntime in a new lxterm..."
lxterminal --command="bash -c './bin/tfliteRuntime; exec bash'" &

# plateSender를 새로운 lxterm에서 실행
echo "Running plateSender in a new lxterm..."
lxterminal --command="bash -c './bin/plateSender; exec bash'" &

# rtspServer를 새로운 lxterm에서 실행 (LD_PRELOAD 설정)
echo "Running rtspServer with LD_PRELOAD in a new lxterm..."
lxterminal --command="bash -c 'LD_PRELOAD=/usr/lib/aarch64-linux-gnu/libcamera/v4l2-compat.so ./bin/rtspServer; exec bash'" &

# usrReceiver를 새로운 lxterm에서 실행
echo "Running usrReceiver in a new lxterm..."
lxterminal --command="bash -c './bin/usrReceiver; exec bash'" &

wait
echo "All processes are running in separate lxterms."


#!/bin/sh
cd ../mjpg-streamer/mjpg-streamer-experimental
sudo ./mjpg_streamer -i "./input_uvc.so -f 10 -r 640x480 -d /dev/video0 -y -n" -o "./output_http.so -w ./www -p 8080" 
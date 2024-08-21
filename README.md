# RemoteRasEye
RemoteRasEye is a general-popused application that can remotely detect, measure, and inspect objects based on stream captured by a camera module on Raspberry Pi. This app consists of 2 sources: the "RemoteRasEye" directry is for Rasoberry Pi, and the DetectFace.py is for laptop PC. It currently has the only functions to detect human's faces and to measure the distance between Raspberry Pi and the object. Additional functions will be commited one by one.

RemoteRasEye is originally written for creating a versatile camera system using raspberry pi remotely so that it can support rapsberry pi users to turn their ideas into reality.

![Overview20240821 drawio](https://github.com/user-attachments/assets/697a7978-e6df-409c-a9fc-8bb0971aa23f)

## Environments
### Hardware
- Raspberry Pi 4 model B
- Ultrasonic module (HC-SR04)
- USB camera module (Akozonbtn0k51m6q)
- Laptop (ThinkPad T480s)

### OSes
- Debian 11 (bullseye)
- Windows10

### Programming Language
- C
- Python 3.8.10

### Tools
- gcc 10.2.1
- WiringPi
- mjpg-streamer
- OpenCV

### Circuit
![Breadboard](https://github.com/user-attachments/assets/9754f8f1-7589-459b-b0f7-586ada63755b)
![Circuite](https://github.com/user-attachments/assets/d83dbff2-bc72-4738-842d-395a25c04d83)

## Prerequisites
1. Setting up mjpg-streamer
Please refer to the following repository and build mjpg-streamer in your Raspberry Pi.
https://github.com/neuralassembly/mjpg-streamer

If you use Bullseye and the error "E: Package 'libjpeg8-dev' has no installation candidate" occures, the following command might help you to install mjpg-streamer.
```
sudo apt update
sudo apt install -y git cmake libjpeg-dev
cd ~/
git clone https://github.com/neuralassembly/mjpg-streamer.git
cd mjpg-streamer/mjpg-streamer-experimental
make
```

2. Installing WiringPi
To access GPIO in C for Raspberry Pi,  install and build WiringPi.
```
git clone https://github.com/WiringPi/WiringPi.git
cd WiringPi
./build
```

## Usage
### Raspbian
1. Fetch the source code.
```
git clone https://github.com/MaithaBin/RemoteRasEye.git
```
2. Compile the codes.
```
cd RemoteRasEye/RemoteRasEye
make
```
3. Run the program.
```
./RemoteRasEye
```
As soon as the program runs, the distance between ultrasonic module and the object is shown in the terminal. The accurately detectable range is 2 cm to 400 cm, even though this program also displays the distance either less than 2 cm or over than 400 cm.

![RasEye](https://github.com/user-attachments/assets/ea9c8173-08df-4202-8246-167bdfa58551)

### Laptop
1. Download the program.
```
git clone https://github.com/MaithaBin/RemoteRasEye.git
```
2. Open Detectface.py and fix the mjpg-streamer URL properly.
```
# MJPEG stream URL
stream_url = "http://127.0.0.0:8080/?action=stream"
```
3. Run the python code.
```
cd RemoteRasEye
python DetectFace.py
```
If successful, the program detects human's faces drwaing grean rectangle.

![PythonCodeUDP](https://github.com/user-attachments/assets/038cb229-bc66-451e-86e9-bcb2863e9beb)

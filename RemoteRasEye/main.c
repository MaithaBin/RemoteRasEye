#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "ultrasonic.h"
#include "client.h"
#include "logging.h"

// All Errror Messages
char ERROR[3][64] = {
	"Failed to setup MJPEG-Streamer.",
	"Failed to setup wiringPi.",
	"Failed to send UDP message."
};

int main(void){
    // TBD: it works in background if successful for now, but error(=-1) won't be returned.
    // Runs MJPG-streamer in background.
    if(system("sudo ./RunMJPEG-streamer.sh &") == -1){
        writeLog(ERROR[0]);
        return 1;
    }
    
    // Initializes wiring
    float distance;
    if(wiringPiSetup() == -1){
        writeLog(ERROR[1]);
        return 1;
    }
    
    ultrasonicInit();
    
    char result[BUF_SIZE];
	if (udpInit() == -1){
        writeLog(ERROR[2]);
		printf("socket error\n");
		return -1;
	}
    
    while(1){
        distance = distanceMeasure();
        sprintf(result, "%0.1f", distance);
        udpSend(result);
        delay(100);
    }
    
    udpClose();

    return 0;
}

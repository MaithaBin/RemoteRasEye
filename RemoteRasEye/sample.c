#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "ultrasonic.h"
#include "logging.h"

char ERROR[3][64] = {
	"Failed to setup MJPEG-Streamer.",
	"Failed to setup wiringPi.",
	"Failed to "
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
    
    while(1){
        distance = distanceMeasure();
        printf("%0.1f cm\n\n",distance);
        delay(100);
    }
    

    return 0;
}

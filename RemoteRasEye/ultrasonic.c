#include "ultrasonic.h"
#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>

// Initilizing Echo and Trig pins for HC-SR04
void ultrasonicInit(void)
{
    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);
}

// Measuring distance in the range of 2 cm to 4 m
// Note: distance which is even either less than 2 cm or longer than 4 m will be return.
float distanceMeasure(void)
{	 
    struct timeval tv_send;
    struct timeval tv_recv;
    long time_send, time_recv;
	float distance;

	// Clears Trig pin.
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);

	// Keeps Trig pin on High for 10 us.
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
	
	// Gets time that ultrasonic pulse is sent out.
	// The loop makes sure that no interfering signal comes when trigger signal sent.
    while(!(digitalRead(Echo) == 1));
    gettimeofday(&tv_send, NULL);

	// Gets time thta ultrasonic pulse.
	// The loop waits for the echo eignal to be received.
    while(!(digitalRead(Echo) == 0));
    gettimeofday(&tv_recv, NULL);

	// Calculates the distance in cm
	// Note: sound speed is 340 m/s = 34000 cm/s
    time_send = tv_send.tv_sec * 1000000 + tv_send.tv_usec;
    time_recv  = tv_recv.tv_sec * 1000000 + tv_recv.tv_usec;

    distance = (float)(time_recv - time_send) / 1000000 * 34000 / 2;

    return distance;
}

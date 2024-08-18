CC = gcc
CFLAG = 
SRCS = sample.c ultrasonic.c logging.c
OBJS = sample.o ultrasonic.o logging.o
INCLUDE = 


RemoteRasEye: sample.o ultrasonic.o logging.o
	$(CC) -o RemoteRasEye sample.o ultrasonic.o logging.o -l wiringPi
	rm -rf *.o
	
sample.o: sample.c
	$(CC) -c sample.c

ultrasonic.o: ultrasonic.c
	$(CC) -c ultrasonic.c
	
logging.o: logging.c
	$(CC) -c logging.c
	



	

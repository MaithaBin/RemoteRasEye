CC = gcc
CFLAG = 
SRCS = main.c ultrasonic.c logging.c
OBJS = main.o ultrasonic.o logging.o
INCLUDE = 


RemoteRasEye: main.o ultrasonic.o logging.o
	$(CC) -o RemoteRasEye main.o ultrasonic.o logging.o -l wiringPi
	rm -rf *.o
	
main.o: main.c
	$(CC) -c main.c

ultrasonic.o: ultrasonic.c
	$(CC) -c ultrasonic.c
	
logging.o: logging.c
	$(CC) -c logging.c
	



	

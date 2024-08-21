CC = gcc
CFLAG = 
SRCS = main.c ultrasonic.c logging.c client.c
OBJS = main.o ultrasonic.o logging.o client.o
INCLUDE = 


RemoteRasEye: main.o ultrasonic.o logging.o client.o
	$(CC) -o RemoteRasEye main.o ultrasonic.o logging.o client.o -l wiringPi
	rm -rf *.o
	
main.o: main.c
	$(CC) -c main.c

ultrasonic.o: ultrasonic.c
	$(CC) -c ultrasonic.c
	
logging.o: logging.c
	$(CC) -c logging.c
	
client.o: client.c
	$(CC) -c client.c
	



	

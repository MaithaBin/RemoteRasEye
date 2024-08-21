#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "client.h"

int socket_desc;

// Initializing socket
int udpInit()
{
	socket_desc = socket(AF_INET, SOCK_DGRAM, 0);
	if (socket_desc == -1){
		return -1;
	} else {
		return 0;
	}
}

// Sending a message to the server over UDP
int udpSend(char* distance){
	char send_buf[BUF_SIZE];
	int send_size;
	struct sockaddr_in addr;
	socklen_t addr_len = sizeof(addr);
	
	// Sets up the server's IP adress and port number.
	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons((unsigned short)PORT);
	addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	// Sends a message
	strcat(distance, " cm");
	strcpy(send_buf, distance);
	send_size = sendto(socket_desc, send_buf, strlen(send_buf) + 1, 0, (struct sockaddr*)&addr, addr_len);
	// Checks whther sending error happens or not
	if (send_size == -1){
		return 1;
	}
	return 0;
}

// Closing socket
void udpClose(){
	close(socket_desc);
}

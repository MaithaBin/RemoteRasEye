#ifndef CLIENT_H
#define CLIENT_H

int udpSend(char* distance);
int udpInit();
void udpClose();

#define SERVER_ADDR "127.0.0.0"
#define PORT 5000
#define BUF_SIZE 1024

#endif // CLIENT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 5555
#define IP "127.0.0.1"

int sendbuf[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

int main()
{
     int sock;
     struct sockaddr_in saddr;
     sock = socket(AF_INET, SOCK_DGRAM, 0);

     if (sock < 0)
     {
        printf("Socket wasn't created\n");
        exit(1);
     }

     saddr.sin_family = AF_INET;
     saddr.sin_port = htons(PORT);
     saddr.sin_addr.s_addr = inet_addr(IP);

     int N = sendto(sock, sendbuf, sizeof(sendbuf), 0, (sockaddr *)&saddr, sizeof(saddr));
     printf("send %d bytes\n", N);

     close(sock);
}


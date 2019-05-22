#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 5555
#define IP_D "127.0.0.1"

int main()
{
     int sock, len;
     int buf[1472];
     struct sockaddr_in saddr, daddr;
     sock = socket(AF_INET, SOCK_DGRAM, 0);

     if (sock < 0)
     {
        printf("Socket wasn't created\n");
        exit(1);
     }

     saddr.sin_family = AF_INET;
     saddr.sin_port = htons(PORT);
     saddr.sin_addr.s_addr = 0;

     daddr.sin_family = AF_INET;
     daddr.sin_addr.s_addr = inet_addr(IP_D);

     if (bind(sock,(struct sockaddr *)&saddr,sizeof(saddr)) < 0)
     {
         printf("Error bind");
         exit(2);
     }

     len = sizeof(daddr);
     int N = recvfrom(sock, buf, 1472, 0, (struct sockaddr *) &daddr, (socklen_t *)&len);
     printf("recive %d bytes\n", N);

     for (unsigned int i = 0; i < N / sizeof(int); i++)
     {
        printf("buf[%d] = %d \n", i, buf[i]);
     }

     close(sock);
}

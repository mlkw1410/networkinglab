#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;
    char buffer[100] = "hello server";
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(3003);

    sendto(sockfd, buffer, 100, 0, (struct sockaddr*)&server , sizeof(server));
    close(sockfd);
    return 0;

}
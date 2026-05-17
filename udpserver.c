#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;
    char buffer[100];
    struct sockaddr_in server, client;
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(3003);

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));

    len = sizeof(client);

    recvfrom(sockfd, buffer, 100, 0 , (struct sockaddr*)&client, &len);
    printf("\nData received from client: %s", buffer);

    close(sockfd);
    return 0;
}

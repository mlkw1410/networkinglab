#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char buf[100];
    int k;
    int sock_desc, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);

    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_desc == -1)
    {
        printf("\nerror in socket creation ");
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 3003;

    k = bind(sock_desc, (struct sockaddr *)&server, sizeof(server));
    if(k== -1)
    {
        printf("\nerror in binding \n");
    }

    k = listen(sock_desc, 5);
    if (k== -1)
    {
        printf("\nerror in listening \n");
    }

    printf("\nwaiting for client connection \n");

    client_sock = accept(sock_desc, (struct sockaddr *)&client, &client_len);
    if (client_sock == -1)
    {
        printf("\nerror in accepting client connection");
    }

    k = recv(client_sock, buf, 100, 0);
    if (k== -1)
    {
        printf("\nerror in recieving data\n ");
    }
    else
    {
        printf("\ndata recieved from client: %s", buf);
    }

    close(client_sock);
    close(sock_desc);
    return 0;
}
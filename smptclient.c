#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int s;
    struct sockaddr_in a;
    char b[1000];

    s = socket(AF_INET, SOCK_STREAM, 0);

    a.sin_family= AF_INET;
    a.sin_addr.s_addr= inet_addr("127.0.0.1");
    a.sin_port= htons(2525);

    connect(s, (struct sockaddr*)&a, sizeof(a));

    memset(b,0, sizeof(b));
    read(s,b,1000);
    printf("%s", b);

    send(s, "HELO client\r\n", 13, 0);
    memset(b, 0, sizeof(b));
    read(s,b, 1000);
    printf("server(HELO REPLY): %s", b);

    send(s, "MAIL FROM:<test@gmail.com>\r\n", 28,0);
    memset(b, 0, sizeof(b));
    read(s,b,1000);
    printf("server(MAIL REPLY): %s", b);

    send(s, "RCPT TO:<recipient@hmail.com>\r\n", 31, 0);
    memset(b, 0, sizeof(b));
    read(s,b,1000);
    printf("server(RCPT REPLY): %s", b);

    send(s, "DATA\r\n", 6, 0);
    memset(b,0, sizeof(b));
    read(s,b,1000);
    printf("server(data reply): %s", b);

    send(s, "THIS IS THE MAIL BODY\r\n.\r\n.", 23, 0);
    send(s, ".\r\n", 3, 0);
    memset(b, 0, sizeof(b));
    read(s,b,1000);
    printf("server reply: %s", b);

    send(s, "QUIT\r\n", 6,0);
    memset(b,0, sizeof(b));
    read(s,b,1000);
    printf("server quit reply: %s", b);

    close(s);
    return 0;

}
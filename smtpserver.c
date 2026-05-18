#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int s = socket(AF_INET, SOCK_STREAM, 0), c;
    struct sockaddr_in a;

    char b[1000];
    
    a.sin_family = AF_INET;
    a.sin_addr.s_addr = INADDR_ANY;
    a.sin_port = htons(2525);

    bind(s, (struct sockaddr *)&a, sizeof(a));

    listen(s, 1);

    c=accept(s, NULL, NULL);

    send(c, "220 smpt server ready \r\n", 18, 0);

    while(read(c,b, 1000)>0)
    {
        if(!strncmp(b, "HELO", 4)) send(c, "250 hello\r\n", 11, 0);
        else if(!strncmp(b, "MAIL", 4)) send(c, "250 ok\r\n", 8,0);
        else if(!strncmp(b, "RCPT", 4)) send(c, "250 ok\r\n", 8, 0);
        else if(!strncmp(b, "DATA", 4)) send (c, "354 end with .\r\n", 17, 0);
        else if(!strncmp(b, ".", 1)) send(c, "250 done\r\n", 8,0);
        else if(!strncmp(b, "QUIT", 4)) send(c, "221 bye\r\n", 8, 0);
    }
}
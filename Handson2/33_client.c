/*
	33. Write a program to communicate between two machines using socket.
*/
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <netinet/in.h>  

int main(){
    struct sockaddr_in server;
    int socket_desc;
    char buff[80];
    socket_desc = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(43456);
    
    connect(socket_desc, (void *)(&server), sizeof(server));
    write(socket_desc,"hello server", 13);
    read(socket_desc, buff, sizeof(buff));
    
    printf("Message from server: %s\n", buff);

    return 0;
}

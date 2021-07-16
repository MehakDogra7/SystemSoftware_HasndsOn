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
    struct sockaddr_in server, client;
    int socket_desc, size_client, new_sd;
    char buff[1024];
    socket_desc = socket(AF_INET,SOCK_STREAM,0);//creates unnamed socket in the kernel
//AF_INET-IPv4
//SOCK_STREAM-reliable protocol(TCP Protocol)
//0-default protocol used by the kernel
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(43456);
    
    bind(socket_desc, (void *)(&server), sizeof(server));
    
    listen(socket_desc,1);
    size_client = sizeof(client);
    
    new_sd = accept(socket_desc, (void *)(&client),&size_client);
    read(new_sd, buff, sizeof(buff));
    printf("Message from client: %s\n", buff);
    write(new_sd,"ACK from server", 16);

    return 0;
}

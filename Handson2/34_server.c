#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <sys/types.h>  


int main(){
    struct sockaddr_in server, client;
    int socket_desc, size_client, new_sd;
    char buff[1024];
    socket_desc = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(43456);
    bind(socket_desc, (void *)(&server), sizeof(server));
    listen(socket_desc,3);

    while(1){
        size_client = sizeof(client);
        new_sd = accept(socket_desc, (void *)(&client),&size_client);
        if(fork() == 0){
            read(new_sd, buff, sizeof(buff));
            printf("Message from client: %s\n", buff);
            write(new_sd,"ACK from server", 16);
        }else{
            close(new_sd);
        }
    } 
    return 0;
}

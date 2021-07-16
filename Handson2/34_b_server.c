#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <sys/types.h>  


void *connection_handler(void *socket_desc){
    char buff[1024];
    int sock = *((int *)socket_desc);
    read(sock, buff, sizeof(buff));
    printf("Message from client: %s\n", buff);
    write(sock, "ACk fromserver", 16);
    close(sock);
    pthread_exit(NULL);
}

int main(int args, char const *argv[]){
    struct sockaddr_in server, client;
    int socket_desc, size_client, new_sd;
    socket_desc = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(43456);
    bind(socket_desc, (void *)(&server), sizeof(server));
    listen(socket_desc,3);

    while(1){
        pthread_t thread_id;
        size_client = sizeof(client);
        new_sd = accept(socket_desc, (void *)(&client),&size_client);
        /*
        int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);

        */
        int abc=pthread_create(&thread_id, NULL, connection_handler,(void *)&new_sd);
        if(new_sd == 1){
            printf("Server queue is full\n");
        }
        else if(abc<0){
            perror("Could not creat thread");
            return 1;
        }else{
            close(new_sd);
        }
    } 
    return 0;
}

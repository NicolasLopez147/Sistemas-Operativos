#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 3535
#define BACKLOG 5
int main(){
    int serverfd, clientfd, r ,opt = 1;
    struct sockaddr_in server,client;
    socklen_t tamano = sizeof(client);

    serverfd = socket(AF_INET,SOCK_STREAM,0);
    if (serverfd < 0){
        perror("Error en socket");
        exit(-1);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;
    bzero(server.sin_zero,8);

    setsockopt(serverfd,SOL_SOCKET,SO_REUSEADDR,(const char *)&opt,sizeof(int));

    r = bind(serverfd,(struct sockaddr *)&server,sizeof(struct sockaddr));
    if (r < 0 ){
        perror("Error en bind");
        exit(-1);
    }
    r = listen(serverfd,BACKLOG);
    if (r < 0 ){
        perror("Error en LISTEN");
        exit(-1);
    }
    clientfd = accept(serverfd, (struct sockaddr *)&client, &tamano);
    if (clientfd < 0){
        perror("Error en el accept");
        exit(-1);
    }
    r = send(clientfd,"Hola asnco",10,0);
    if (r < 0 ){
        perror("Error en send");
        exit(-1);
    }
    close(clientfd);
    close(serverfd);
}
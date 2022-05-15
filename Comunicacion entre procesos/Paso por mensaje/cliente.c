#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>


#define PORT 3535
#define IP "127.0.0.1"
int main(){
    int clientefd, r;
    struct sockaddr_in client;
    struct hostent *he;
    char buffer[32];
    
    clientefd = socket(AF_INET,SOCK_STREAM,0);
    if (clientefd < 0){
        perror("Error creando el socket\n");
        exit(-1);
    }
    client.sin_family = AF_INET;
    client.sin_port = htons(PORT);
    inet_aton(IP,&client.sin_addr);

    r =connect(clientefd,(struct sockaddr *)&client,(socklen_t)sizeof(struct sockaddr));
    if (r < 0){
        perror("Error en connect\n");
        exit(-1);
    }
    r = recv (clientefd,buffer,32,0);
    buffer[r] = 0;
    printf("Mensaje recibido: %s",buffer);
    close(clientefd);
}
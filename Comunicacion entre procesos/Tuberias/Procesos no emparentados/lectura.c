#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    //Descriptor del archivo
    int t;
    //Ruta del archivo tuberia
    char *tuberia = "./tuberia"; 

    //Se abre la tuberia
    t = open(tuberia,O_RDONLY);
    if (t < 0){
        perror("Hubo un error abriendo el archivo de la tuberia");
        exit(-1);
    }

    //Se lee el mensaje de la tuberia
    char buffer[11];
    int r = read(t,buffer,10);
    if (r < 0){
        perror("Hubo un error leyendo el archivo de la tuberia");
        exit(-1);
    }
    buffer[r] = 0;
    printf("El mensaje recibido fue %s \n",buffer);
    close(t);
    return 0;
}
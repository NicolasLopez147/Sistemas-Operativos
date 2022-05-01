#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    //Descriptor del archivo
    int t;
    //Ruta del archivo tuberia
    char *tuberia = "./tuberia"; 

    //Crear un archivo de tipo fifo
    mkfifo(tuberia,0666);

    /*
    TIpos de apertura de tuberias
    O_RDONLY - ABRIR SOLO LECTURA
    O_WRONLY - ABRIR SOLO ESCRITURA
    O_RDWR - ABRIR LECTURA / ESCRITURA
    O_APPEND - AGREGAR AL FINAL DEL ARCHIVO
    */
    t = open(tuberia,O_WRONLY);
    if (t < 0){
        perror("Hubo un error abriendo el archivo de la tuberia");
        exit(-1);
    }
   
    //Escribimos el mensaje
    char saludo [] = "Hola mundo";
    int r = write(t,saludo,sizeof(saludo));
    close(t);
    unlink(tuberia);
    return 0;
}
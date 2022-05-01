#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;
    int r;
    int pipefd[2];
    char buffer[11];

    //Se crea la tuberia, r sera 0 si todo sale bien o -1 si algo sale mal
    r = pipe(pipefd);
    if(r < 0){
        perror("Hubo un error con la creacion de la tuberia"); 
        exit(-1);
    }

    //Se crea un proceso hijo
    pid = fork();
    if (pid < 0){
        perror("Hubo un problema con la creacion del proceso hijo");
        exit(-1);
    }
    //Proceso hijo
    if (pid == 0){
        printf("El descirptor de lectura del hijo es %d \n",pipefd[0]);
        printf("El descirptor de escritura del hijo es %d\n",pipefd[1]);
        //EL proceso hijo escribira un mensaje en la tuberia que el padre leera
        //Por lo que se cerrara el descriptor de lectura del hijo
        close(pipefd[0]);
        char saludo []= "Hola mundo";
        //Write retornara -1 si hubo algun error o retornara el numero de 
        // bytes usados en el buffer, en este caso saludo
        //A la funcxion write se le pasa el descriptor, el buffer y el tamaño del buffer
        r = write(pipefd[1],saludo , sizeof(saludo));
        if (r < 0){
            perror("Hubo un problema al escribir el saludo");
            exit(-1);
        }   
        //Cerramos el descriptor de escritura despues de usarlo
        close(pipefd[1]);
    }
    //Proceso padre
    else {
        printf("El descirptor de lectura del padre es %d\n",pipefd[0]);
        printf("El descirptor de escritura del padre es %d\n",pipefd[1]);
        //EL proceso padre leera de la tuberia por lo que cerramos el descriptor de escritura
        close(pipefd[1]);
        //r retornara -1 si hubo algun error o el numero de bytes usados si no lo hubo
        r = read(pipefd[0],buffer,10);
        if (r < 0){
            perror("Hubo un error al leer la tuberia");
            exit(-1);
        }
        buffer[r] = 0;
        printf("\nEl mensaje del hijo es: %s \n",buffer);
    }
}
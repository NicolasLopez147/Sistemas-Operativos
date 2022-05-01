#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

struct perro {
    char nombre[32];
    int edad;
    char raza[16];
    int estatura;
    float peso;
    char sexo;
};

int guardar(void *ap){
    FILE *fd;
    fd = fopen("dataDogs.dat","a+");
    fwrite(ap,sizeof(struct perro),1,fd);
    fclose(fd);
}

int main (){
    pid_t pid;
    key_t key  = 1234;
    int shmId ,*flag;
    void *ap;
    struct perro *aPerro;
    int status, cpid;

    shmId = shmget(key,sizeof(struct perro)+sizeof(int),0666);
    if (shmId < 0){
        perror("Error en shmget");
        exit(0);
    }
    ap = shmat(shmId,0,0);
    aPerro = (struct perro*) ap;
    flag = (int *)(ap+sizeof(struct perro));
    guardar(aPerro);
    *flag = 0;
    shmdt(ap);
}
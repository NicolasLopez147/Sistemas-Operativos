#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    key_t key = 1234;
    int shmId;
    float a, b, c, *ap;
    int status, cpid, r;

    shmId = shmget(key, sizeof(float) * 3, 0666 | IPC_CREAT);
    if (shmId < 0)
    {
        perror("Error en shmet");
        exit(-1);
    }
    ap = (float *)shmat(shmId, 0, 0);
    *ap = 3.1416;
    pid = fork();
    if (pid < 0)
    {
        perror("Error fork");   
        exit(-1);
    }
    if (pid == 0)
    { // Hijo
        *(ap + 1) = 0.707;
    }
    else
    {
        if (wait(&status) == pid)
        {
            printf("\nDato *ap: %f \nDato *(ap+1): %f\n", *ap, *(ap + 1));
        }
    }
    r = shmdt(ap);
    if (r < 0)
    {
        perror("Error shmdt");
        exit(-1);
    }
}

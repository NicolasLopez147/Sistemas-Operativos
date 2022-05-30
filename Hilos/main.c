#include <stdlib.h>
#include <stdio.h> 
#include <math.h>
#include <pthread.h>

#define NUM_HILOS 16
#define MAXITER 1e09

struct datos
{
    int a;
    char b;
};

float y;

int  * funcion(void *datos){
    double x = 0.0;
    int i;
    struct datos *datosH;
    datosH = datos;
    printf("\na = %i b = %c",datosH->a,datosH->b);
    fflush(stdout);
    // for (i = 0 ; i < MAXITER ; i++)
    //     x = sin(i);
    return 0;
}

int main (){
    pthread_t hilo[NUM_HILOS] ;
    struct datos datosh[NUM_HILOS];

    int r , *rh0;
    
    for (int i = 0; i < NUM_HILOS ; i++){
        datosh[i].a = i;
        datosh[i].b = 'A'+i;
    }
    for (int i = 0 ; i < NUM_HILOS ; i ++){
        r = pthread_create(&hilo[i],NULL,(void *)funcion , (void *)&datosh[i]);
        if (r != 0){
            perror("\n pthread_create error");
            exit(-1);
        }
    }
    for (int i = 0 ; i < NUM_HILOS ; i ++){
        r = pthread_join(hilo[i],(void **)&rh0);
        if (r != 0){
            perror("\n pthread_join error");
            exit(-1);
        }
    }
    printf("\n");
    return 0;

}
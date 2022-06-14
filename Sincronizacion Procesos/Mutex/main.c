#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PROCESOS 1
#define NUM_HILOS 8

pthread_mutex_t mutex;

struct datos_tipo
{
    int data;
    int p;
};

int * proceso (void * datos){
    struct datos_tipo *datos_proceso;
    datos_proceso = (struct datos_tipo *) datos;
    int a , p;

    a = datos_proceso->data;
    p = datos_proceso->p;
    // Inicio seccion critica
    pthread_mutex_lock(&mutex);
    for (int i = 0 ; i <= p ; i ++){
        printf("%i",a);
    }
    fflush(stdout);
    sleep(1);
    for (int i = 0; i < p; i++)
    {
        printf("---");
    }
    fflush(stdout);

    pthread_mutex_unlock(&mutex);
    //Fin seccion critica
    return 0;
}

int main (){
    int error,r;
    char *valor_devuelto;
    struct datos_tipo hilo_datos[NUM_HILOS];
    pthread_t idhilo [NUM_HILOS];
    r = pthread_mutex_init(&mutex,NULL);
    if (r != 0){
        printf("Fallo iniciando mutex");
        exit(-1);
    }

    for (int i = 0 ; i < NUM_HILOS ; i ++){
        hilo_datos[i].data = i;
        hilo_datos[i].p = i+1;
    }

    for (int i  =0 ; i < NUM_HILOS ; i ++){
        error = pthread_create(&idhilo[i],NULL,(void*)proceso,(void*)(&hilo_datos[i]));
        if (error != 0 ){
            perror("No se creo el hilo");
            exit(-1);
        }
    }
    for (int i = 0 ; i < NUM_HILOS ; i ++){
        pthread_join(idhilo[i],(void**)&valor_devuelto);
    }
    r = pthread_mutex_destroy(&mutex);
    if (r != 0){
        printf("Fallo cerrando mutex");
        exit(-1);
    }

    printf("\n");
    return 0;
}
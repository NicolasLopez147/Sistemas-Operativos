#include <stdlib.h>
#include <stdio.h>

void main(){
    FILE *mifichero;
    mifichero = fopen("prueba.txt","r");
    int c;
    //mifichero = fopen("prueba.txt","w");
    //fprintf(mifichero,"%s","hola mundo");
    // if (mifichero != NULL){
    //     printf("Funciona: \n");
    // }
    while(1){
        c = fgetc(mifichero);
        if (feof(mifichero)){
            break;
        }
        printf("%c",c);
    }
    fclose(mifichero);
}
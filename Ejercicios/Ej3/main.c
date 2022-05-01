#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	FILE * archivo = fopen("prueba.txt","r");
	if (!archivo){
		exit(EXIT_FAILURE);
	}
	char linea;
	int contador = 1;
	printf("%d ",contador);
	while((linea = fgetc(archivo))!= EOF){
		printf("%c",(linea));
		if (linea == '\n'){
			if ((linea = fgetc(archivo))!= EOF){
				contador++;
				printf("%d %c",contador,linea);
			}
			
		}
	}
	fclose(archivo);
}

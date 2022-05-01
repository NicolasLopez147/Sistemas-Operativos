#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	FILE * archivo = fopen("prueba.txt","r");
	if (!archivo){
		exit(EXIT_FAILURE);
	}
	char linea;
	
	while((linea = fgetc(archivo))!= EOF){
		printf("%c",toupper(linea));
	}
	fclose(archivo);
}

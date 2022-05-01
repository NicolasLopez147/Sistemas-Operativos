#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fichero;
	fichero = fopen("salidatexto.txt", "wt");
	int cantidad;
	scanf("%d",&cantidad);
	for(int i = 1; i <= cantidad; i++) {
		fputs("*", fichero);
	}
	fclose(fichero);
	printf("Completado");
	return 0;
}

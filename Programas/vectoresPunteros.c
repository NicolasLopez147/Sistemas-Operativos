#include <stdio.h>
#include <stdlib.h>

int main(){
	int arreglo[7];
	int  *punt;
	punt = &arreglo[0];
	*punt = 5;
	*(punt+2) = 3;
	
	for (int i = 0 ; i < 7 ; i ++){
		printf(" %d",arreglo[i]);
	}
	printf("\n");
	return 0;
}

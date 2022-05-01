#include<stdio.h>
#include<stdlib.h>

void suma(int *x,int *y,int *z){
	*x = *x+2;
	*y = *y+2;
	*z = *z+2;
}
int main(void){
	int x;
	int y;
	int z;
	printf("Introdusca tres numeros enteros ");
	scanf("%d &d &d",&x,&y,&z);
	suma(&x,&y,&z);
	printf("%d %d %d",x,y,z);
	return 0;
}

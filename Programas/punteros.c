#include <stdio.h>
#include <stdlib.h>

int  main(){
	int  *punt;
	int x;
	int y;
	punt = &x;
	*punt = 4;
	punt = &y;
	*punt = 8;
	printf("%d, %d, %d\n",x,y,x*y);
	return 0;
}

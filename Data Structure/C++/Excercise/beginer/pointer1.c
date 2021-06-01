#include <stdio.h>
#include <conio.h>


int main(){
	int *p;
	p = NULL;
	p = (int*) malloc(6 * sizeof(int*));
	
	int i;
	for (i=0; i < 6; i++){
		scanf("%d", &(*(p + i)));
	}
	for (i=0; i < 6; i++){
		printf("%d \n", *(p + i));
	}
	
	printf("%d", *(p + 3));
	free(p);
}

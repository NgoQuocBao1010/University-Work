#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char file_name[100], h[100];
	int n, i, count=0;
	
	scanf("%s", file_name);
	
	FILE *f = fopen(file_name, "r");
	
	while (fgets(h, 100, f) != '\0')
	count ++;
	
	printf("%d", count);
	
	fclose(f);
}

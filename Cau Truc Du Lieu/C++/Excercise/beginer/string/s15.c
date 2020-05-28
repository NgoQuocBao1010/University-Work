#include <stdio.h>
#include <string.h>
void mystrcpy(char *s1, char *s2){
	int i;
	
	for (i=0; i<=strlen(s1); i++){
		s2[i] = s1[i];
		
	}
}
int main(){
	char c[100];
mystrcpy("Hello World", c);
printf("%s", c);
}

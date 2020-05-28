#include <stdio.h>
#include <string.h>

char* subString(char s[], int pos, int number){
	char* des;
	int i;
	des = (char*)malloc((number + 1)*sizeof(int));
	
	for (i = 0; i < number; i++){
		des[i] = s[pos];
		pos++;
	}
	des[number] = '\0';
	return des;
}
int main(){
	char *st="toi di hoc";
char *res = subString(st, 4,2);
puts(st);
puts(res);
free(res);
}

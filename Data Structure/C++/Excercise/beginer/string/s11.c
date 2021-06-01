#include <stdio.h>
#include <string.h>
void Delete(int p, char st[]){
	int n = strlen(st);
	int i;
	for (i = p; i<n;i ++){
		st[i] = st[i+1];
	}
	st[n] = '\0';
}
int main(){
	char str[500];
fgets(str,500,stdin);
printf("%s",str);
Delete(3,str);
printf("%s",str);
}

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
	char s[500];
	int i, n, p;
	
	fgets(s, 500, stdin);
	
	n = strlen(s);
	
	if (s[n -1] == '\n'){
		--n;
		s[n] = '\0';
	}
	
	for (i=0; i<=n; i++){
		
		if (s[i]== ' ' && s[i+1]== ' '){
			p = i + 1;
			Delete (p,s);
			p = 0;
			i--;
		}

	}
	
	
	if (s[0] == ' ')
	Delete(0, s);
	
	puts(s);
}

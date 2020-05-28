#include <stdio.h>
#include <string.h>
int main(){
	char s[500];
	
	int i, n;
	
	fgets(s, 500, stdin);
	n = strlen(s);
	
	if (s[n -1] == '\n'){
		--n;
		s[n] = '\0';
	}
	puts(s);
	
	for (i=0; i<n/2; i++){
		if (s[i] != s[n-1-i]){
		
			puts("NO");
			return 0;	}
	}
	puts("YES");
	
}

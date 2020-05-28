#include <stdio.h>
#include <string.h>
int main(){
	int i, n;
	char s[500];
	
	fgets(s, 500, stdin);
	
	n = strlen(s);
	
	if (s[n -1] == '\n'){
		--n;
		s[n] = '\0';
	}
	puts(s);
	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] = s[0] - 32;
	
	for (i=1; i<n; i++){
		if (s[i] != ' ' && s[i-1] == ' '){
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = s[i] - 32;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] + 32;
	}
	puts(s);
	return 0;
}


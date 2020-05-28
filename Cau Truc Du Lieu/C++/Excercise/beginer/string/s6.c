#include <stdio.h>
#include <string.h>
int Compare(char s1[], char s2[]){
	int i, d;
	i=0;
	
	
	while (s1[i] != '\0'){
		if (s1[i] >= 'A' && s1[i] <= 'Z'){
			s1[i] = s1[i] + 32;
		}
		i++;
	}
	
	i=0;
	   
	while (s2[i] != '\0'){
		if (s2[i] >= 'A' && s2[i] <= 'Z'){
			s2[i] = s2[i] + 32;
		}
		i++;
	}
	
	i=0;
	
	d=0;
	
	while (s1[i] != 0 && s2[i] != 0 && d == 0){
		d = s1[i] - s2[i];
		i++;
	}
	return d;
}
int main(){
	char s[100], x[100];
	int i, n, m, d;
	
	fgets(s, 100, stdin);
	n = strlen(s);
	
	if (s[n -1] == '\n'){
		--n;
		s[n] = '\0';
	}
	fgets(x, 100, stdin);
	m = strlen(x);
	
	if (x[n -1] == '\n'){
		--n;
		x[n] = '\0';
	}
	
	d = Compare(s, x);
	
	if (d == 0)
		printf("1 = 2");
	else if (d < 0)
			printf("1 < 2");
		else
			printf("1 > 2");
	
}

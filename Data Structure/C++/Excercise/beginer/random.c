#include <stdio.h>
int main ()
{
	int h, p, s, sogiay;
	
	scanf("%dh%dm%ds", &h, &p, &s);
	
	sogiay = h * 3600 + p * 60 + s;
	
	printf("Number of seconds: %d", sogiay);
	
	return 0;
	
	
	
	
	
	
}

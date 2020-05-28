#include <stdio.h>
int main()
{
	int sg, h, p,s;
	
	scanf("%d", &sg);
	
	
	h = sg / 3600;
	
	p = (sg - h * 3600)/60; 
	
	s = sg - h* 3600 - p * 60;
	
	printf("%02d:%02d:%02d", h, p, s);
	return 0;
	
	
	
	
	
}

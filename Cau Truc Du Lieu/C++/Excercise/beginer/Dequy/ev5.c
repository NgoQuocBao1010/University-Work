#include <stdio.h>
int max3(int a, int b, int c){
	if (a>=b && a>=c)
	return a;
	if (b>=a && b>=c)
	return b;
	if (c>=b && c>=a)
	return c;
}
int main(){
	printf("%d\n", max3(5, 5, 2));
}

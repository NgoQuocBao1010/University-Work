#include <stdio.h>
float my_abs(float x){
	if (x<0)
	return -x;
	else 
	return x;
}
int main(){
	
	printf("%.2f\n", my_abs(-35.1));
}

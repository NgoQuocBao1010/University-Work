#include <stdio.h>
double power(float a, int n){
	double s=1;
	int i;
	for ( i=1; i<=n; i++){
		s= s*a;
	}
	return s;
}
int main(){
printf("%.4f\n", power(-2.0, 5));
}

#include <stdio.h>
int checkPrime(long longs p){
	int i;
	if (p<2)
	return 0;
	else if(p==2)
	return 1;
	else if (p%2==0)
	return 0;
	
	for (i=3; i<p; i=i+2){
		if(p%i==0)
		return 0;
	}
	return 1;
}
int main(){
	int i;
for (i = 2; i <= 10; i++)
    printf("%d %d\n", i, checkPrime(i));
}

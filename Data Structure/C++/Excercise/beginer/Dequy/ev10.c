#include <stdio.h>
int isPrime(int p){
	if (p<2)
	return 0;
	else if(p==2)
	return 1;
	else if (p%2==0)
	return 0;
	int i;
	for (i=3; i<p; i= i+2){
		if (p%i==0)
		return 0;
	}
	return 1;
}
void printPrimeNumbers(int a, int b){
	int i;
	for (i=a; i<=b; i++){
		if (isPrime(i) == 1){
			printf("%d ", i);
		}
	}
}
int main(){
	printPrimeNumbers(4, 4);
}

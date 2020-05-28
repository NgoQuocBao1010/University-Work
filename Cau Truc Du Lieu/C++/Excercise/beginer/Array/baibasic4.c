#include <stdio.h>
int isPrime(int p){
	int i;
	if (p<2)
	return 0;
	else if (p==2)
	return 1;
	else if (p%2==0)
	return 0;
	
	for (i=3; i<p; i){
			if (p%i == 0)
			return 0;	
		
		
	}
	return 1;
	
}
int main(){
	int A[100], n , i, count;
	
	scanf("%d", &n);
	count=0;
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
		if (isPrime(A[i])==1)
		count ++;
	}
	for(i=0; i<n; i++){
		printf("%d ", A[i]);
	}
	printf("\n%d \n", count);
	for(i=0; i<n; i++){
		if (isPrime(A[i])==1)
		printf("%d ", A[i]);
	}
	
	
}

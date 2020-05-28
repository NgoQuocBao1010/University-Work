#include <stdio.h>
int main(){
	int A[100], n, i;
	scanf("%d", &n);
	
	for (i=0; i<n; i++){
		scanf("%d", &A[i]);
		printf("%d ", A[i]);
		
	}
	printf("\n");
	for (i=n-1; i>=0; i=i-1){ 
		printf("%d ", A[i]);
	}
}

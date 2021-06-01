#include <stdio.h>
int main()
{
	int A[100], i, n, kq;
	
	scanf("%d", &n);
	kq = 0;
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
		kq = kq + A[i] * A[i];
	}
	for(i=0; i<n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	printf("%d", kq);
	
	
	return 0;
}

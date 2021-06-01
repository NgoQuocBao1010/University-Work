#include <stdio.h>
void copyOddNumbers(int A[], int N, int B[], int *pM){
	int i;
	*pM = 0;
	for (i=0; i<N; i++){
		if(A[i] % 2 != 0){
			B[(*pM)] = A[i];
			(*pM)++;
		}
	}
}
void printList(int A[], int N){
	int i;
	for (i=0; i<N; i++)
	printf("%d ", A[i]);
	printf("\n");
}
int main(){
	int a[]={1,5,6,8,71,0,12,13,11,18};
int b[1000];
int m,n;

n = sizeof(a)/sizeof(int);
printList(a,n);
copyOddNumbers(a,n,b,&m);
printList(b,m);
}

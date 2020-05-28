#include <stdio.h>
void printList(int A[], int n){
	int i;
	for (i=0; i< n; i++){
		printf("%d ", A[i] );
	}
	printf("\n");
}
void copyOddNumbers(int A[], int N, int B[], int *pM){
	int i, j;
	*pM = 0;
	
	for (i = 0; i < N; i++){
		if (A[i] % 2 != 0){
		B[(*pM)] = A[i];
		(*pM)++;
		}
	}
}
void getMax(int A[], int n, int *pMaxValue, int *pMaxPos){
	int i;
	*pMaxValue = -1;
	for (i = 0; i < n; i++){
		if (A[i] > (*pMaxValue)){
			*pMaxValue = A[i];
			*pMaxPos = i;
		}
	}
}
int* getSequence(int n, int d){
	int *a;
	int i;
	a = (int*) malloc(n*sizeof(int*));
	*a = 1;
	for (i=1; i<=n; i++)
	
	*(a + i) =  *(a + i -1) + d;
	
	return a;
	
}
void Insert(int x, int p, int A[], int *pn){
	
	int i;
	
	for (i=*pn-1; i>=p; i--){
		A[i + 1] = A[i];   
	}
	A[p] = x;
	*pn = *pn + 1;

}
void Delete(int p, int A[], int *pn){
	int i;
	for (i=p; i < *pn; i++)
	A[i] = A[1+i];
	*pn = *pn -1;
}
void add(int a, int b, int *c){
	*c = a + b;
}
int main(){
	int c;
add(5, 2, &c);
add(c, -8, &c);
printf("%d\n", c);	
}


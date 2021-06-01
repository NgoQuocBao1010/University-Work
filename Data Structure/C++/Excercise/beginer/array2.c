#include <stdio.h>
void makeReverse(int A[], int n){
	int i, emp=0;
	
	for (i=0; i < n/2; i++){
		emp = A[i];
		A[i] = A[n-1-i];
		A[n -1 -i] = emp;
	}
	
}
int locate(int x, int A[], int n){
	int i;
	for (i = 0; i < n; i++){
		if (x == A[i])
		return i;
	}
	return n;
}
void printList(int A[], int n){
	int  i;
	
	for (i=0; i < n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}
void readList(int A[], int n){
	int  i;
	
	for (i=0; i < n; i++){
		scanf("%d", &A[i]);
	}
}
int maxA(int A[], int n){
	int  i, max = -1;
	
	for (i=0; i < n; i++){
		if (A[i] > max)
		max = A[i];
	}
	return max;
}
int minA(int A[], int n){
	int  i, min = 1000;
	
	for (i=0; i < n; i++){
		if (A[i] < min)
		min = A[i];
	}
	return min;
}
void getFibo(int A[], int n){
	int i;
	if (n == 0 || n == 1){
		for (i = 0; i < n + 1; i++)
		A[i] = 1;
	}
	else {
		A[0] = 1;
		A[1] = 1;
		for (i = 2; i < n + 1; i++)
		A[i] = A[i-2] + A[i -1];
	}
}
int main(){
	int n;
int a[1000];
scanf("%d",&n); // So phan tu
readList(a,n);	 //Nhap mang
printf("Print list: ");
printList(a,n);
printf("Print again: ");
printList(a,n);
}


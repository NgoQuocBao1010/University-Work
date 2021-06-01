#include <stdio.h>
void getFibo(int A[], int n){
	int i;
	if (n == 0 || n == 1){
		for (i = 0; i < n; i++)
		A[i] = 1;
	}
	else {
		A[0] = 1;
		A[1] = 1;
		for (i = 2; i < n; i++)
		A[i] = A[i-2] + A[i -1];
}
int main(){
	int A[50];
int i,n;
n=10;
getFibo(A,n);
for(i=0;i<=n;i++)
printf("%d ",A[i]);}

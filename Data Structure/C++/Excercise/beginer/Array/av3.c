#include <stdio.h>
float getAVG(int A[], int n){
	float kq, avg;
	int i;
	for (i=0; i<n; i++){
		kq = kq + A[i];
	}
	avg = kq / n;
	return avg;
}
int main(){
	int A[]={1,2,3,4}; //Mang A
int n,i;
n = sizeof(A)/sizeof(int); // So phan tu

for(i=0;i<=n-1;i++)
    printf("%d ",A[i]);
printf("\nAVG %.4f",getAVG(A,n));
}

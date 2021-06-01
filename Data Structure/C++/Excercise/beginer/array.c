#include <stdio.h>
int isPrime(int p){
	int i;
	if (p < 2)
	return 0;
	else if (p == 2)
		return 1;
		else if (p % 2 == 0)
			return 0;
	
	for (i = 3; i < p; i =i +2){
		if (p % i == 0)
		return 0;
	}
	return 1;
}
int isSort(int A[], int n){
	int i;
	
	for (i=0; i < n-1; i++){
		if (A[i+1] < A[i])
		return 0;
	}
	return 1;
}
int isPalindrome(int A[], int n){
	int i;
	for (i = 0; i < n; i++){
		if (A[i] != A[n -1 -i])
		return 0;
	}
	return 1;
}
int main(){
	int A[]={1, 2, 3, 3, 2, 1, 0};
int n = sizeof(A)/sizeof(int);
printf("%d",isPalindrome(A,n));
}

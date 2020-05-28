#include <stdio.h>
int* getSequence(int n, int d){
	int k=1, *t, i;
	
	t = (int *)(n*sizeof(int));
	
	for (i=0; i<n; i++){
		t[i] = k;
		k = k + d;
	}
	
	return t;
}
int main(){
	int *a;
int n=6, d=3;
int i;
a=getSequence(n,d);
for(i=0;i<=n-1;i++)
    printf("%d ",a[i]);
free(a);
}

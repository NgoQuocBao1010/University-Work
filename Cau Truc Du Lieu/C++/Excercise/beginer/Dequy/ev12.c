#include <stdio.h>
long long sum(int n){
	if (n==0)
	return 0;
	
	return sum(n-1)+n;
}
int main(){
	long long S = sum(1234);
printf("%lld", S);
}

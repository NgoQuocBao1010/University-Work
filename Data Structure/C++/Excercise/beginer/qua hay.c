#include<stdio.h>
int main()
{
	float lt, t1, t2, t3, t4, tb;
	
	scanf("%f%f%f%f%f", &lt, &t1, &t2, &t3, &t4);
	
	tb = ( lt + (t1+t2+t3+t4)/4.0)/2.0;
	
	printf("Ly thuyet: %.2f\n", lt);
	printf("Thuc hanh 1: %.2f\n", t1);
	printf("Thuc hanh 2: %.2f\n", t2);
	printf("Thuc hanh 3: %.2f\n", t3);
	printf("Thuc hanh 4: %.2f\n", t4);
	printf("Trung binh: %.2f\n", tb);
	
	if (tb < 4) printf("BI DUOI HOC");
	else printf("DAT YEU CAU");
	return 0;
	
	
	
}

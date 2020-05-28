#include <stdio.h>


void factorize(int n)
{
	int i;
		
		i=2;
		printf("%d = ", n);
			
			while ( n != 1)
			
			
				{
					if (n % i == 0)
					{
						n = n/i;
						
						if (n>1)
						printf("%d x ", i);
						else 
						printf("%d",i);
					}
						else
							i = i + 1;
				}
				
				
						
				
			
		
	
			
		
}
int main()
{
	factorize(638);
	
}



#include <iostream>

int max_sequence( int arr[], int n )  
{  
    int lis[n]; 
    int maxElement = -1;
   
    lis[1] = 1;    
  
    for (int i = 2; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 1; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
        
        if (lis[i] > maxElement)
            maxElement = lis[i];
    } 
  
    return maxElement; 
}  

int main() 
{ 
	int n = 14; //phần tử A[0] không sử dụng nhé !
    int A[] = {0, 7, 3, 2, 5, 4, 2, 6, 2, 7, 1, 3, 2, 9, 0};
	printf("Length of lis is %d", 
		max_sequence( A, n )); 
	return 0; 
} 

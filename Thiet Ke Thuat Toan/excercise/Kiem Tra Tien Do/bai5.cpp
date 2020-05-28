#include <iostream>
using namespace std;

void swap(long long* a, long long* b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}

long long partition (long long arr[], long long low, long long high)
{
    long long pivot = arr[high];  // selecting last element as pivot
    long long i = (low - 1);  // index of smaller element
 
    for (long long j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
/*  
    a[] is the array, p is starting index, that is 0, 
    and r is the last index of array.  
*/
void quicksort(long long a[], long long p, long long r)    
{
    if(p < r)
    {
        long long q;
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}



void estimateProfit(const char* fileName){
    long long numOfPro;
    freopen(fileName, "r", stdin);

    cin >> numOfPro;
    // int* a1 = new int[SIZE];
    long long* farms = new long long[numOfPro];
    long long* valueOfProfits = new long long[numOfPro];

    for (long long i=0; i<numOfPro; i++){
        cin >> farms[i];
    }

    for (long long i=0; i<numOfPro; i++){
        cin >> valueOfProfits[i];
    }
    
    quicksort(farms, 0, numOfPro - 1);
    quicksort(valueOfProfits, 0, numOfPro - 1);




    long long maxProfit = 0;

    for (long long i=0; i<numOfPro; i++){
        maxProfit += farms[i] * valueOfProfits[i];
    }

    cout << maxProfit << endl;
}
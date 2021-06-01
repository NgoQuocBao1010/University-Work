#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    int part1[size1], part2[size2];

    for (int i=0; i < size1; i++){
        part1[i] = arr[low + i];
    }

    for (int i=0; i < size2; i++){
        part2[i] = arr[mid + 1 + i];
    }


    // merge 2 parts
    int i = 0;
    int j = 0;
    int k = low;
    while (i < size1 && j < size2){
        if (part1[i] <= part2[j]){
            arr[k] = part1[i];
            i++;
        }
        else {
            arr[k] = part2[j];
            j++;
        }
        k++;
    }

    while (i < size1){
        arr[k] = part1[i];
        i++;
        k++;
    }

    while (j < size2){
        arr[k] = part2[j];
        j++;
        k++;
    }

}


void mergeSort(int arr[], int low, int high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void sort(int arr[], int size){
    mergeSort(arr, 0, size - 1);
}


void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    sort(arr, arr_size);
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
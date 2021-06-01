#include <iostream>
using namespace std;

// ====================== Merge Sort Integer ======================
// ======================    Small to Big    ======================
void merge(int arr[], int low, int mid, int high){
    int size1, size2;

    // Seperate current arr into 2 parts 
    // from the mid position
    size1 = mid - low + 1;
    size2 = high - mid;

    int* part1 = new int[size1];
    int* part2 = new int[size2];

    for (int i=0; i < size1; i++){
        part1[i] = arr[low + i];
    }
    for (int i=0; i < size2; i++){
        part2[i] = arr[mid + 1 + i];
    }


    // Merge and sorted 2 parts 
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
    delete[] part1;
    delete[] part2;
}

void mergeSort(int arr[], int low, int high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}



// ====================== Merge Sort Long Long ======================
// ======================    Small to Big    ======================
void mergell(long long arr[], long long low, long long mid, long long high){
    long long size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    long long* part1 = new long long[size1];
    long long* part2 = new long long[size2];
    // long long part1[size1], long long part2[size2];

    for (long long i=0; i < size1; i++){
        part1[i] = arr[low + i];
    }

    for (long long i=0; i < size2; i++){
        part2[i] = arr[mid + 1 + i];
    }


    // merge 2 parts
    long long i = 0;
    long long j = 0;
    long long k = low;
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
    delete[] part1;
    delete[] part2;
}

void mergeSortll(long long arr[], long long low, long long high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSortll(arr, low, mid);
        mergeSortll(arr, mid + 1, high);

        mergell(arr, low, mid, high);
    }
}



// ====================== Merge Sort Integer ======================
// ======================    Big to Small    ======================
void mergeReverse(int arr[], int low, int mid, int high){
    int size1, size2;

    // Seperate current arr into 2 parts 
    // from the mid position
    size1 = mid - low + 1;
    size2 = high - mid;

    int* part1 = new int[size1];
    int* part2 = new int[size2];

    for (int i=0; i < size1; i++){
        part1[i] = arr[low + i];
    }
    for (int i=0; i < size2; i++){
        part2[i] = arr[mid + 1 + i];
    }


    // Merge and sorted 2 parts 
    int i = 0;
    int j = 0;
    int k = low;
    while (i < size1 && j < size2){
        if (part1[i] >= part2[j]){
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
    delete[] part1;
    delete[] part2;
}

void mergeSortReverse(int arr[], int low, int high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSortReverse(arr, low, mid);
        mergeSortReverse(arr, mid + 1, high);

        mergeReverse(arr, low, mid, high);
    }
}


// ====================== Merge Sort Long Long ======================
// ======================    Big to Small    ======================
void mergellReverse(long long arr[], long long low, long long mid, long long high){
    long long size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    long long* part1 = new long long[size1];
    long long* part2 = new long long[size2];
    // long long part1[size1], long long part2[size2];

    for (long long i=0; i < size1; i++){
        part1[i] = arr[low + i];
    }

    for (long long i=0; i < size2; i++){
        part2[i] = arr[mid + 1 + i];
    }


    // merge 2 parts
    long long i = 0;
    long long j = 0;
    long long k = low;
    while (i < size1 && j < size2){
        if (part1[i] >= part2[j]){
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
    delete[] part1;
    delete[] part2;
}

void mergeSortllReverse(long long arr[], long long low, long long high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSortllReverse(arr, low, mid);
        mergeSortllReverse(arr, mid + 1, high);

        mergellReverse(arr, low, mid, high);
    }
}





void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1);
    
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 

    mergeSortReverse(arr, 0, arr_size - 1);

    printf("\nSorted reversed array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
#include <stdio.h>
#include <stdlib.h>

void merge(long long arr[], long long low, long long mid, long long high){
    long long size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    long long* part1 = (long long*) malloc(size1 * sizeof(long long));
    long long* part2 = (long long*) malloc(size2 * sizeof(long long));

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

}

void mergeSort(long long arr[], long long low, long long high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

long long multiArr(long long arr[], int size){
    long long result = 1;
    for (int i=0; i<size; i++)
        result *= arr[i];
    return result;
}

void whatTheFrickIsThisShit(){
    long long sizeOfArr;
    scanf("%lld", &sizeOfArr);

    long long* calculateArr = (long long*) malloc(3 * sizeof(long long));
    long long* result = (long long*) malloc(sizeOfArr * sizeof(long long));

    for (long long i=0; i<sizeOfArr; i++){
        long long element;
        scanf("%lld", &element);

        if (i < 2){
            result[i] = -1;
            calculateArr[i] = element;
            continue;
        }
        
        if (i == 2){
            calculateArr[i] = element;
        }

        if (i > 2){
            mergeSort(calculateArr, 0, 3);
            
            if (calculateArr[0] < element){
                calculateArr[0] = element;
            }
        }
        result[i] = multiArr(calculateArr, 3);
    }

    for (long long i=0; i<sizeOfArr; i++){
        printf("%lld\n", result[i]);
    }
}

int main(){
    // whatTheFrickIsThisShit();
    long long arr[4] = {18468, 6335, 26501, 19170};
    mergeSort(arr, 0, 3);
    for (int i=0; i<4; i++){
        printf("%lld\n", arr[i]);
    }
}
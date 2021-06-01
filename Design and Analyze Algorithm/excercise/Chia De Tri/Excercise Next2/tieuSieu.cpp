#include <stdio.h>
#include <stdlib.h>


// ====================== Merge Sort Long Long ======================
// ======================    Small to Big    ======================
void mergell(long long arr[], long long low, long long mid, long long high){
    long long size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    long long* part1 = (long long*) malloc(size1*sizeof(long long));
    long long* part2 = (long long*) malloc(size2*sizeof(long long));
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
    free(part1);
    free(part2);
}

void mergeSortll(long long arr[], long long low, long long high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSortll(arr, low, mid);
        mergeSortll(arr, mid + 1, high);

        mergell(arr, low, mid, high);
    }
}

// Binary Search Long long
// Similar to the above function except for the data type
// This function is more effiecent for long and large SORTED array.
long long binarySearchLongLong(long long arr[], long long startIndex, long long endIndex, long long value){
    if (endIndex >= startIndex){
        long long mid = startIndex + (endIndex - startIndex) / 2;

        if (arr[mid] == value)
            return mid;
        
        if (arr[mid] > value)
            return binarySearchLongLong(arr, startIndex, mid - 1, value);
        
        return binarySearchLongLong(arr, mid + 1, endIndex, value);
    }
    return -1;
}

void tieuSieu(){
    long long numOfRecords;
    // cin >> numOfRecords;
    scanf("%lld", &numOfRecords);

    // long long* records = new long long[numOfRecords];
    long long* records = (long long*) malloc((numOfRecords) * sizeof(long long));

    for (long long i=0; i<numOfRecords; i++)
        scanf("%lld", &records[i]);
        // cin >> records[i];
    
    mergeSortll(records, 0, numOfRecords-1);

    long long numOfQues;
    scanf("%lld", &numOfQues);
    // cin >> numOfQues;

    long long record;
    for (long long i=0; i<numOfQues; i++){
        scanf("%lld", &record);
        long long index = binarySearchLongLong(records, 0, numOfRecords-1, record);
        printf("%lld\n", index+1);
    }
}

int main() {
    // freopen("testInput.txt", "r", stdin);
    tieuSieu();
}
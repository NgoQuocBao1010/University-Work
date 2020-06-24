#include <iostream>
#include <unordered_map>
using namespace std;

#define MaxSize 1001
#define MinValue -1

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


// ======================    Solve Problem   ======================
long long solveDP(int arr[], int size, int total) {
    long long* mem = new long long[total + 1];

    for (int i=0; i<=total; i++ )
        mem[i] = 0;
    
    mem[0] = 1;

    for (int i=0; i<size; i++) {
        long long value = arr[i];

        for (int j=value; j<=total; j++) {
            mem[j] += mem[j - value];
        }
    }
    return mem[total];
}

void waysToPay() {
    int numOfVal, totalVal;
    cin >> numOfVal >> totalVal;

    int* values = new int[numOfVal];

    for (int i=0; i<numOfVal; i++)
        cin >> values[i];

    mergeSort(values, 0, numOfVal - 1);
    cout << solveDP(values, numOfVal, totalVal);
}

int main() {
    freopen("testInput.txt", "r", stdin);
    waysToPay();
    return 0;
}
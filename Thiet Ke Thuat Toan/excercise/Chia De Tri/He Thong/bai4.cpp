#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void merge(long long arr[], long long low, long long mid, long long high){
    long long size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    long long* part1 = new long long[size1];
    long long* part2 = new long long[size2];

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


void search(const char* fileName){
    freopen(fileName, "r", stdin);

    long long size, numOfquestions;
    cin >> size >> numOfquestions;

    long long* arr = new long long[size];

    for (long long i=0; i<size; i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, size-1);

    long long ques;
    for (long long i=0; i<numOfquestions; i++){
        cin >> ques;
        if (binarySearchLongLong(arr, 0, size-1, ques) == -1){
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}


int main(){
    search("test.txt");
}
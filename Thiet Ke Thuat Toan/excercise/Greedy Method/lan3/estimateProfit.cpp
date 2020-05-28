#include <iostream>
using namespace std;

void merge(long long arr[], long long low, long long mid, long long high){
    long long size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    long long* part1 = new long long[size1];
    long long* part2 = new long long[size2];
    // long long part1[size1];
    // long long part2[size2];

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

void mergeSort(long long arr[], long long low, long long high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
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
    
    mergeSort(farms, 0, numOfPro - 1);
    mergeSort(valueOfProfits, 0, numOfPro - 1);


    long long maxProfit = 0;

    for (long long i=0; i<numOfPro; i++){
        maxProfit += farms[i] * valueOfProfits[i];
    }

    cout << maxProfit << endl;
    // delete[] farms;
    // delete[] valueOfProfits;
}
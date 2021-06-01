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

long long nextPos(long long arr[], long long target, long long end) 
{ 
    long long start = 0; 
  
    long long ans = -1; 
    while (start <= end) 
    { 
        long long mid = (start + end) / 2; 
   
        if (arr[mid] <= target) 
            start = mid + 1; 

        else
        { 
            ans = mid; 
            end = mid - 1; 
        } 
    } 
  
    return ans; 
}

void minhminh(){
    long long numOfDays, numOfQues;
    cin >>  numOfDays >> numOfQues;

    long long* tempsArr = new long long[numOfDays];

    for (long long i=0; i<numOfDays; i++){
        if (i==0) {
            cin >> tempsArr[i];
            continue;
        }
        int newTemps;
        cin >> newTemps;
        tempsArr[i] = tempsArr[i-1] + newTemps;
    }

    for (long long i=0; i<numOfQues; i++){
        int newQues;
        cin >> newQues;
        for (long long j=0; j<numOfDays; j++){
            int result = nextPos(tempsArr, newQues, numOfDays);
            if (result != -1){
                cout << result + 1 << endl;
                break;
            }
        }
    }

    // for (long long i=0; i<numOfDays; i++){
    //     cout << copyArr[i] << "\t";
    // }
    // for (long long i=0; i<numOfDays; i++){
    //     cout << tempsArr[i] << "\t";
    // }
}


int main(){
    minhminh();
}
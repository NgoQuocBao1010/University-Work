#include <iostream>
using namespace std;

void mergeInStyle(int arr[], int lookUpArr[], int low, int mid, int high){
    int size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    int part1[size1], part2[size2];
    int arrPart1[size1], arrPart2[size2];

    for (int i=0; i < size1; i++){
        part1[i] = lookUpArr[low + i];
        arrPart1[i] = arr[low + i];
    }

    for (int i=0; i < size2; i++){
        part2[i] = lookUpArr[mid + 1 + i];
        arrPart2[i] = arr[mid + 1 + i];
    }


    // merge 2 lookUpArrays
    int i = 0;
    int j = 0;
    int k = low;
    while (i < size1 && j < size2){
        if (part1[i] <= part2[j]){
            lookUpArr[k] = part1[i];
            arr[k] = arrPart1[i];
            i++;
        }
        else {
            lookUpArr[k] = part2[j];
            arr[k] = arrPart2[j];
            j++;
        }
        k++;
    }

    while (i < size1){
        lookUpArr[k] = part1[i];
        arr[k] = arrPart1[i];
        i++;
        k++;
    }

    while (j < size2){
        lookUpArr[k] = part2[j];
        arr[k] = arrPart2[j];
        j++;
        k++;
    }

}


void mergeSortInStyle(int arr[], int lookUpArr[], int low, int high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSortInStyle(arr, lookUpArr, low, mid);
        mergeSortInStyle(arr, lookUpArr, mid + 1, high);

        mergeInStyle(arr, lookUpArr, low, mid, high);
    }
}

void sortInStyle(int arr[], int lookUpArr[], int size){
    mergeSortInStyle(arr, lookUpArr, 0, size - 1);
}


void bai3(){
    int numOfJobs;
    cin >> numOfJobs;

    int profits[numOfJobs], deadlines[numOfJobs];

    for (int i=0; i<numOfJobs; i++){
        cin >> profits[i];
    }
    for (int i=0; i<numOfJobs; i++){
        cin >> deadlines[i];
    }

    // sortInStyle(deadlines, profits, numOfJobs);
    sortInStyle(profits, deadlines, numOfJobs);

    // printArray(profits, numOfJobs);
    // printArray(deadlines, numOfJobs);
    

    int i = 0;
    int maxProfit = 0, max = profits[0];

    while (i < numOfJobs){

        if (profits[i] > max) max = profits[i];

        if (i == numOfJobs - 1) {
            maxProfit += max;
            break;
        }
        else if (deadlines[i] != deadlines[i + 1]) {
            maxProfit += max;
            max = profits[i + 1];
        }

        i++;
    }

    cout << maxProfit << endl;
    
}

int main(){
    bai3();
}
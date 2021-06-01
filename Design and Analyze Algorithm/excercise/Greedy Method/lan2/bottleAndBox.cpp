#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int size1, size2;

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


void bottleAndBox(){
    int numOfTestCases;
    cin >> numOfTestCases;

    for (int t=0; t<numOfTestCases; t++){
        int numOfBottles, volOfBox;
        cin >> numOfBottles >> volOfBox;

        int* volOfBottles = new int[numOfBottles];

        for (int i=0; i<numOfBottles; i++)
            cin >> volOfBottles[i];
        
        mergeSort(volOfBottles, 0, numOfBottles-1);

        int fullBottles = 0;

        for (int i=0; i<numOfBottles; i++){
            if (volOfBottles[i] > volOfBox) break;
            
            volOfBox -= volOfBottles[i];
            fullBottles++;
        }
        cout << fullBottles << endl;
    }
}

void solve(const char* filename){
    freopen(filename, "r", stdin);
    bottleAndBox();
}

int main(){
    // solve("test.txt");
    cout << "HEllo";
}
#include <iostream>
#include <algorithm>
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



int nextPos(int arr[], int target, int end) 
{ 
    int start = 0; 
  
    int ans = -1; 
    while (start <= end) 
    { 
        int mid = (start + end) / 2; 
   
        if (arr[mid] < target) 
            start = mid + 1; 

        else
        { 
            ans = mid; 
            end = mid - 1; 
        } 
    } 
  
    return ans; 
}


void demTraSua(const char* fileName){
    freopen(fileName, "r", stdin);
    int numOfTea;
    cin >> numOfTea;

    int* priceOfTeas = new int[numOfTea];

    for (int i=0; i<numOfTea; i++)
        cin >> priceOfTeas[i];
    
    mergeSort(priceOfTeas, 0, numOfTea - 1);
    
    int numOfQues;
    cin >> numOfQues;

    for (int i=0; i<numOfQues; i++){
        int money;
        cin >> money;
        // cout << money << endl;

        int result = nextPos(priceOfTeas, money, numOfTea - 1);

        if (result == -1)
            result = numOfTea;
        cout << result << endl;
    }
}

int main(){
    demTraSua("test.txt");
}
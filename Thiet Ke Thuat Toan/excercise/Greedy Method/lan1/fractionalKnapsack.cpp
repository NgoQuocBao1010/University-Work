#include <iostream>
#include <algorithm>
using namespace std;
// ************************* Item *************************
typedef struct{
    int value;
    int weight;
} Item;

// ************************* Merge Sort *************************
void merge(Item arr[], long long low, long long mid, long long high){
    long long size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    Item* part1 = new Item[size1];
    Item* part2 = new Item[size2];

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
        if ((double) part1[i].value / part1[i].weight >= (double) part2[j].value / part2[j].weight){
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

void mergeSort(Item arr[], long long low, long long high){
    if (low < high){
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}


// Take in the max weight, SORTED item array and its size as parameter
// Return the profit
double fractionalKnapsack(int maxWeight, Item itemArr[], int size){

    int knapsackWeight = 0;
    double knapsackValue = 0.0;

    for (long long i=0; i<size; i++){
        if (knapsackWeight + itemArr[i].weight <= maxWeight){
            knapsackWeight += itemArr[i].weight;
            knapsackValue += itemArr[i].value;
        }
        else {
            int remain = maxWeight - knapsackWeight;
            knapsackValue += itemArr[i].value * ((double) remain / (double) itemArr[i].weight);
            break;
        }
    }

    return knapsackValue;
}

void helpingTheThief(){
    int numOfItems, maxWeight;
    cin >> numOfItems >> maxWeight;

    int* itemsWeight = new int[numOfItems];

    Item* itemArr = new Item[numOfItems];

    for (long long i=0; i<numOfItems; i++)
		cin >> itemsWeight[i];
	
    for (long long i=0; i<numOfItems; i++){
        int value;
        cin >> value;
        Item newItem = {value, itemsWeight[i]};
        itemArr[i] = newItem;
    }

    mergeSort(itemArr, 0, numOfItems-1);

    // for (long long i=0; i<numOfItems; i++){
    //     cout << itemArr[i].value << ", " << itemArr[i].weight << endl;
    // }
    printf("%.4lf" ,fractionalKnapsack(maxWeight, itemArr, numOfItems));
}


int main(){
    helpingTheThief();
}
#include <stdio.h>
#include <stdlib.h>

#define MINVALUE -10000007

void merge(int arr[], int low, int mid, int high){
    int size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    // int* part1 = new int[size1];
    // int* part2 = new int[size2];
    int* part1 = (int*) malloc(size1*sizeof(int));
    int* part2 = (int*) malloc(size2*sizeof(int));

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

void recordsOfJonas(){
    int numOfRecs;
    // cin >> numOfRecs;
    scanf("%d", &numOfRecs);

    // int* recordsList = new int[numOfRecs+1];
    int* recordsList = (int*) malloc((numOfRecs+1) * sizeof(int));

    for (int i=1; i<=numOfRecs; i++)
        scanf("%d", &recordsList[i]);
        // cin >> recordsList[i];
    
    mergeSort(recordsList, 1, numOfRecs);

    int numOfQues;
    // cin >> numOfQues;
    scanf("%d", &numOfQues);

    // int* result = new int[numOfQues];
    int *result = (int*) malloc(numOfQues*sizeof(int));

    for (int i=0; i<numOfQues; i++){
        int rank;
        char type;
        // cin >> rank >> type;
        scanf("%d %c", &rank, &type);

        int index;
        if (type == 'S')
            index = rank;
        else 
            index = numOfRecs - rank + 1;
        
        result[i] = recordsList[index];
    }
    for (int i=0; i<numOfQues; i++){
        // cout << result[i] << endl;
        printf("%d\n", result[i]);
    }
    // for (int i=0; i<=numOfRecs; i++){
    //     cout << recordsList[i] << endl;
    // }
}


int main(){
    recordsOfJonas();
}
#include <iostream>
using namespace std;


// Bài 1
int recursiveLargest(int arr[], int largest, int position){
    if (position == 0){
        return largest;
    }
    
    if (arr[position] > largest){
        largest = arr[position];
    }
    return recursiveLargest(arr, largest, position - 1);
}

int getMax(int arr[], int size){
    int largest = arr[0];
    return recursiveLargest(arr, largest, size - 1);
}


//Bài 2
void merge(int arr[], int low, int mid, int high){
    int size1, size2;

    size1 = mid - low + 1;
    size2 = high - mid;

    int part1[size1], part2[size2];

    for (int i=0; i < size1; i++){
        part1[i] = arr[low + i];
    }

    for (int i=0; i < size2; i++){
        part2[i] = arr[mid + 1 + i];
    }


    // merge 2 arrays
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

void sort(int arr[], int size){
    mergeSort(arr, 0, size - 1);
}

void findkSum(const char* fileName){
    int numberOfScore, numberOfQuestions;
    freopen(fileName, "r", stdin);

    cin >> numberOfScore;
    cin >> numberOfQuestions;

    int scoreArray[numberOfScore], questionArray[numberOfQuestions];

    for (int i=0; i < numberOfScore; i++){
        cin >> scoreArray[i];
    }

    for (int i=0; i < numberOfQuestions; i++){
        cin >> questionArray[i];
    }

    sort(scoreArray, numberOfScore);

    int result, k;
    
    for (int i=0; i < numberOfQuestions; i++){
        k = questionArray[i];
        result = 0;

        int j=0;
        while (j < k){
            result = result + scoreArray[numberOfScore - j - 1];
            j++;
        }
        cout << result << endl;
    }
}



// Bài 3
int powerOf2(int n){
    if (n == 0){
        return 1;
    }
    return 2 * powerOf2(n - 1);
}

void recursivePrint(int position, int n){

    if (position == n){
        cout << powerOf2(n);
        return;
    }

    if (position < n){
        cout << powerOf2(position) << " ";
        recursivePrint(position + 1, n);
    }

}

void print2Power(int n){
    recursivePrint(0, n);
}


// Bài 4
void shootOut(const char* fileName){
    int numberOfEnemies, numberOfRounds;

    freopen(fileName, "r", stdin);
    cin >> numberOfEnemies;

    int enemyStrength[numberOfEnemies];

    for (int i=0; i < numberOfEnemies; i++){
        cin >> enemyStrength[i];
    }

    cin >> numberOfRounds;

    int roundStrength[numberOfRounds];

    for (int i=0; i < numberOfRounds; i++){
        cin >> roundStrength[i];
    }

    int enemiesDefeated, damage, strength;
    for (int i=1; i <= numberOfRounds; i++){
        enemiesDefeated = 0;
        damage = 0;
        strength = roundStrength[i - 1];
        
        for (int i=0; i < numberOfEnemies; i++){
            if (strength >= enemyStrength[i]){
                enemiesDefeated ++;
                damage = damage + enemyStrength[i];
            }
        }
        cout << enemiesDefeated << " " << damage << endl;
    }

}


// Bài 5
void printArray(int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


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

void moduloSort(const char* fileName){
    int sizeOfArray, modulo;
    freopen(fileName, "r", stdin);

    cin >> sizeOfArray;
    cin >> modulo;

    int arr[sizeOfArray], moduloArray[sizeOfArray];

    for (int i=0; i < sizeOfArray; i++){
        cin >> arr[i];
        moduloArray[i] = arr[i] % modulo;
    }


    sortInStyle(arr, moduloArray, sizeOfArray);

    printArray(arr, sizeOfArray);
}
 
int main(){
    moduloSort("test.txt");
    return 0;
}
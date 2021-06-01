#include <iostream>
using namespace std;

void printArray(long long arr[], long long size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// bai 1
void bai1(){
    int totalValue, count;
    cin >> totalValue;
    if (totalValue % 10000 != 0 || totalValue < 10000){
        cout << "KHONG RUT DUOC" << endl;
        return;
    }

    int moneyValues[6] = {500000, 200000, 100000, 50000, 20000, 10000};

    int i = 0;

    while (totalValue != 0){
        count = totalValue / moneyValues[i];

        totalValue = totalValue % moneyValues[i];

        if (count > 0)
            cout << moneyValues[i] << " VND: " << count << endl;
        i++;
    }
}


// bai 2
long long maxNum(long long a, long long b){
    if (a > b) return a;
    return b;
}

void findBoundingBox(const char* fileName){
    freopen(fileName, "r", stdin);

    int numberOfHouses;
    cin >> numberOfHouses;

    long long maxY, minY, maxX, minX;

    cin >> maxX;
    cin >> maxY;

    minY = maxY;
    minX = maxX;

    for (int i=1; i<numberOfHouses; i++){
        long long x, y;
        cin >> x;
        cin >> y;

        if (x > maxX) maxX = x;
        else if (x < minX) minX = x;

        if (y > maxY) maxY =y;
        else if (y < minY) minY = y;
    }

    long long side1 = maxY - minY;
    long long side2 = maxX - minX;

    long long result;
    result = maxNum(side1, side2);

    cout << result * result;
}

// bai 3
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


// bai 4
bool isPrime(int n)
{
    // Neu n < 2 thi khong phai la SNT
    if (n < 2){
        return false;
    }       
     
    // Neu n = 2 la SNT
    if (n == 2){
        return true;
    }
     
    // Neu n la so chan thi ko phai la SNT
    if (n % 2 == 0){
        return false;   
    }
     
    // Lap qua cac so le
    for (int i = 3; i < (n - 1); i += 2){
        if (n % i == 0){
            return false;
        }   
    }
     
    return true;
}

void bai4() {
    int number;
    cin >> number;

    if (number == 2){
        cout << number << endl;
        return;
    }

    if (number % 2 == 0) number = number - 1;

    while (!isPrime(number)){
        number -= 2;
    }

    cout << number << endl;
}



// bai 5

void swap(long long* a, long long* b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}

long long partition (long long arr[], long long low, long long high)
{
    long long pivot = arr[high];  // selecting last element as pivot
    long long i = (low - 1);  // index of smaller element
 
    for (long long j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(long long a[], long long p, long long r)    
{
    if(p < r)
    {
        long long q;
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

int insertSorted(long long arr[], long long n, long long value) 
{ 
    int i; 
    for (i = n - 1; (i >= 0 && arr[i] > value); i--) 
        arr[i + 1] = arr[i]; 
  
    arr[i + 1] = value; 

    return (n + 1); 
}

void estimateProfit(const char* fileName){
    long long numOfPro;
    freopen(fileName, "r", stdin);

    cin >> numOfPro;
    // int* a1 = new int[SIZE];
    long long* farms = new long long[numOfPro];
    long long* valueOfProfits = new long long[numOfPro];

    cin >> farms[0];
    for (long long i=1; i<numOfPro; i++){
        long long temp;
        cin >> temp;
        insertSorted(farms, i, temp);
    }

    cin >> valueOfProfits[0]; 
    for (long long i=1; i<numOfPro; i++){
        long long temp;
        cin >> temp;
        insertSorted(valueOfProfits, i, temp);
    }

    // quicksort(farms, 0, numOfPro - 1);
    // quicksort(valueOfProfits, 0, numOfPro - 1);
    // printArray(farms, numOfPro);
    // printArray(valueOfProfits, numOfPro);

    long long maxProfit = 0;

    for (long long i=0; i<numOfPro; i++){
        maxProfit += farms[i] * valueOfProfits[i];
    }

    cout << maxProfit << endl;
}


int main(){
    
    // bai1();
    // bai4();
    // bai3();
    // estimateProfit("VanGroup/vg10.inp");
    findBoundingBox("test.txt");
}
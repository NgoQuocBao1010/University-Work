#include <iostream>

using namespace std;

// Binary Search Integers
// Find the index of element with value of x in a SORTED-array arr.
// Return -1 if arr does not contains x.
int binarySearch(int arr[], int startIndex, int endIndex, int value){
    if (endIndex >= startIndex){
        int mid = startIndex + (endIndex - startIndex) / 2;

        if (arr[mid] == value){
            return mid;
        }

        if (arr[mid] > value)
            return binarySearch(arr, startIndex, mid - 1, value);
        
        return binarySearch(arr, mid + 1, endIndex, value);
    }
    return -1;
}


// Binary Search Long long
// Similar to the above function except for the data type
// This function is more effiecent for long and large SORTED array.
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

int main(){
    int arr[10] = {1, 3, 5, 7, 9, 10, 12, 16, 19, 20};
    cout << binarySearch(arr, 0, 9, 1) << endl;
}
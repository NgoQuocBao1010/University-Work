#include <iostream>
#include <algorithm>
using namespace std;

#define MaxSize 10000007

int findMax(int a, int b) {
    if (a > b) 
        return a;
    return b;
}

int max_sum(int arr[], int n) {
    int maxCurrent, maxGlobal;
    maxCurrent = maxGlobal = arr[0];

    for (int i=1; i<n+1; i++) {
        maxCurrent = findMax(arr[i], maxCurrent + arr[i]);

        if (maxCurrent > maxGlobal)
            maxGlobal = maxCurrent;
    }

    return maxGlobal;
}

int main() {
    int n = 10;
    int A[] = {0, 2, -3, 4, 5, -6, 7, -8, -5, 3, 9};
    cout << max_sum(A, n) << endl;
    return 0;
}


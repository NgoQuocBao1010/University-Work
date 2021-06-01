#include <iostream>
using namespace std;


int max(int a, int b){
    if (a > b) return a;
    return b;
}


// dãy con lớn nhất nằm ở nửa trái
int maxLeft(int arr[], int low, int high){
    int sum = 0;
    int maxSum = INT32_MIN;

    for (int i = high; i >= low; i--){
        sum = sum + arr[i];
        maxSum = max(sum, maxSum);
    }

    return maxSum;
}


// dãy con lớn nhất nằm ở nửa phải
int maxRight(int arr[], int low, int high){
    int sum = 0;
    int maxSum = INT32_MIN;

    for (int i = low; i <= high; i++){
        sum = sum + arr[i];
        maxSum = max(sum, maxSum);
    }

    return maxSum;
}


// dãy con lớn nhất trong đoạn low high
int maxSub(int arr[], int low, int high){
    if (low == high) return arr[low];

    int mid = (low + high) / 2;
    int sLeft = maxSub(arr, low, mid);
    int sRight = maxSub(arr, mid + 1, high);
    int sMid = maxLeft(arr, low, mid) + maxRight(arr, mid + 1, high);
    return max( max(sRight, sLeft), sMid );
}


int max_sum(int arr[], int n){
    int i, sum, ans;

    sum = ans = 0;
    for (i=0; i <= n; i++){
        sum += arr[i];
        ans = max(sum, ans);
        if (sum < 0){
            sum = 0;
        }
    }
    return ans;
}


  
/* Driver program to test above functions */
int main() 
{ 
    int n = 2;
    int A[] = {-1, -2, -3};
    cout << max_sum(A, n) << endl;
} 
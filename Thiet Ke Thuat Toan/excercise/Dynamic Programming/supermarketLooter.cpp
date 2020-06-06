#include <iostream>
#include <algorithm>
using namespace std;

using namespace std; 
  
// Returns the value of maximum profit 
int knapSackRec(int W, int wt[], int val[], 
                int i, int** dp) 
{ 
    // base condition 
    if (i < 0) 
        return 0; 
    if (dp[i][W] != -1) 
        return dp[i][W]; 
  
    if (wt[i] > W) { 
        dp[i][W] = knapSackRec( W, wt, val, i - 1, dp ); 
        return dp[i][W]; 
    } 
    else { 
        dp[i][W] = max( 
            val[i] + knapSackRec( 
                         W - wt[i], wt, val, i - 1, dp), 
                        knapSackRec(W, wt, val, i - 1, dp)); 
  
        return dp[i][W]; 
    } 
} 
  
int knapSack(int W, int wt[], int val[], int n) 
{ 
    
    int** dp; 
    dp = new int*[n]; 
  
    
    for (int i = 0; i < n; i++) 
        dp[i] = new int[W + 1]; 
  
   
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < W + 1; j++) 
            dp[i][j] = -1; 
    return knapSackRec(W, wt, val, n - 1, dp); 
} 

void solveLooters() {
    int testCases;
    cin >> testCases;

    for (int ca=0; ca<testCases; ca++) {
        int items;
        cin >> items;

        int* values = new int[items];
        int* weight = new int[items];

        for (int i=0; i<items; i++) {
            cin >> values[i];
            cin >> weight[i];
        }

        int looters;
        cin >> looters;

        int lootersValue = 0;

        for (int i=0; i<looters; i++) {
            int weightLimit;
            cin >> weightLimit;

            lootersValue += knapSack(weightLimit, weight, values, items);
        }
        cout << lootersValue << endl;
    }
}
  
int main() 
{ 
    freopen("testInput.txt", "r", stdin);
    solveLooters();
    return 0; 
} 
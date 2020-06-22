#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 501

// No of rows and columns 
int n, m; 

// Declaring the matrix of maximum 
// 100 rows and 100 columns 
int a[N][N]; 

// Variable visited is used to keep 
// track of all the visited positions 
// Variable dp is used to store 
// maximum sum till current position 
vector<vector<int> > dp(N, vector<int>(N)), 
	visited(N, vector<int>(N)); 

// For storing current sum 
int current_sum = 0; 

// For continuous update of 
// maximum sum required 
int total_sum = 0; 

// Function to Input the matrix of size n*m 
void inputMatrix() 
{ 
	cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
} 

// Function to calculate maximum sum of path 
int maximum_sum_path(int i, int j) 
{ 
	// Checking boundary condition 
	if (i == n - 1 && j == m - 1) 
		return a[i][j]; 

	// Checking whether or not (i, j) is visited 
	if (visited[i][j]) 
		return dp[i][j]; 

	// Marking (i, j) is visited 
	visited[i][j] = 1; 

	// Updating the maximum sum till 
	// the current position in the dp 
	int& total_sum = dp[i][j]; 

	// Checking whether the position hasn't 
	// visited the last row or the last column. 
	// Making recursive call for all the possible 
	// moves from the current cell and then adding the 
	// maximum returned by the calls and updating it. 
	if (i < n - 1 & j < m - 1) { 
		int current_sum = max(maximum_sum_path(i, j + 1), 
							max( 
								maximum_sum_path(i + 1, j + 1), 
								maximum_sum_path(i + 1, j))); 
		total_sum = a[i][j] + current_sum; 
	} 

	// Checking whether 
	// position has reached last row 
	else if (i == n - 1) 
		total_sum = a[i][j] 
					+ maximum_sum_path(i, j + 1); 

	// If the position is in the last column 
	else
		total_sum = a[i][j] 
					+ maximum_sum_path(i + 1, j); 

	// Returning the updated maximum value 
	return total_sum; 
} 

// Driver Code 
int main() 
{ 
    freopen("testInput.txt", "r", stdin);
	inputMatrix(); 

	// Calling the implemented function 
	int maximum_sum = maximum_sum_path(0, 0); 

	cout << maximum_sum; 
	return 0; 
} 

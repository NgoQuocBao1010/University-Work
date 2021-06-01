#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MinValue -1000007
#define N 501

void mazeSolve() {
	int rows, cols;
	cin >> rows >> cols;

	int** matrix;
	matrix = new int*[N];

    for (int i=0; i<N; i++)
        matrix[i] = new int[N];

	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			cin >> matrix[i][j];
		}
	}
	

	int** mem;
	mem = new int*[N];

    for (int i=0; i<N; i++)
        mem[i] = new int[N];
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            mem[i][j] = MinValue;
        }
    }

	int tmp;
	mem[0][0] = matrix[0][0];
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {		
			if (j + 1 < cols) {
				tmp = mem[i][j] + matrix[i][j + 1];
				if (tmp > mem[i][j + 1])
					mem[i][j + 1] = tmp;
			}

			if (i + 1 < rows) {
				tmp = mem[i][j] + matrix[i + 1][j];

				if (tmp > mem[i + 1][j])
					mem[i + 1][j] = tmp;
			}

			if (i + 1 < rows && j + 1 < cols) {
				tmp = mem[i][j] + matrix[i + 1][j + 1];

				if (tmp > mem[i + 1][j + 1])
					mem[i + 1][j + 1] = tmp;
			}
		}
	}

	cout << mem[rows - 1][cols - 1];
}


int main() { 
    freopen("testInput.txt", "r", stdin);
	mazeSolve();
	return 0; 
} 

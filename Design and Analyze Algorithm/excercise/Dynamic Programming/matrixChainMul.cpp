#include <iostream>

using namespace std;

#define MaxValue 10000007

int solveDP(int d[], int matrices) {
    int table[101][101];

    for (int i=1; i<=matrices; i++) 
        table[i][i] = 0;
    
    int L, i, j, k;

    for (L=2; L<matrices; L++) {
        for (i=1; i < matrices - L + 1; i++) {
            j = i + L - 1;
            table[i][j] = MaxValue;

            for (k=i; k <= j - 1; k++) {
                int value = table[i][k] + table[k + 1][j] + d[i - 1] * d[k] * d[j];

                if (value < table[i][j])
                    table[i][j] = value;
            }
        }
    }
    return table[1][matrices - 1];
}

void matrixMulplication() {
    int matrices;
    cin >> matrices;

    int* d = new int[matrices+1];

    for (int i=0; i<=matrices; i++) 
        cin >> d[i];
    

    cout << solveDP(d, matrices+1);
}

int main() {
    // freopen("testInput.txt", "r", stdin);
    matrixMulplication();
    return 0;
}
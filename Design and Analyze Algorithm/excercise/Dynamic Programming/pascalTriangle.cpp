#include <iostream>
#include <algorithm>
using namespace std;

void pascalTriangle(){
    long long n;
    cin >> n;

    long long mem[51][51];
    mem[0][0] = 1;

    for (long long i=0; i<=n; i++) {
        for (long long j=0; j<=i; j++) {
            if (j == 0 || j == i)
                mem[i][j] = 1;
            else {
                mem[i][j] = mem[i - 1][j - 1] + mem[i - 1][j];
            }
            cout << mem[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    pascalTriangle();
    return 0;
}
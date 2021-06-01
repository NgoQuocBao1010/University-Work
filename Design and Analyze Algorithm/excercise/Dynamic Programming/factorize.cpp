#include <iostream>
#include <algorithm>
using namespace std;

#define MaxSize 10000007

void factorize() {
    int testCases;
    cin >> testCases;

    long long* mem = new long long[MaxSize];
    mem[0] = 1;
    mem[1] = 1;

    for (int c=0; c<testCases; c++) {
        long long n;
        cin >> n;

        if (n == 0 || n == 1) {
            cout << 1 << endl;
            continue;
        }

        mem[n] = (n * mem[n - 1]) % (1000000007);
        cout << mem[n] << endl;
    }
    delete[] mem;
}

int main() {
    factorize();
    return 0;
}


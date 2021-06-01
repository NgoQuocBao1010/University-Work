#include <iostream>
#include <algorithm>
using namespace std;

#define MaxSize 1000007

void trieuMinh() {
    string s;
    getline(cin, s);

    int* mem = new int[MaxSize];

    int count = 0;

    for (int i = s.length()-1; i>=0; i--) {
        int num = (int) (s[i] - '0');
        
        if (num % 2 == 0)
            count ++;
        
        mem[i] = count;
    }

    // for (int i=s.length()-1; i>=0; i--)
    //     cout << mem[i] << " ";

    for (int i=0; (unsigned) i< (unsigned) s.length(); i++)
        cout << mem[i] << " ";
}

int main() {
    trieuMinh();
    return 0;
}
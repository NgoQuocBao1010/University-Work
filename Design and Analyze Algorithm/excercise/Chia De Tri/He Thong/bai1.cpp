#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void modulo(){
    long long a, p;
    cin >> a >> p;

    for (long long i=1; i<=p-1; i++){
        if ((a * i) % p == 1){
            cout << i;
            return;
        }
    }
    cout << -1;
}
int main(){
    modulo();
}
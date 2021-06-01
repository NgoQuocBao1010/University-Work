#include <iostream>
using namespace std;

int reverseNum(int n, int temp){
    if (n < 10) {
        int result = temp * 10 + n;
        return result;
    }

    int num = n % 10;
    return reverseNum(n / 10, temp * 10 + num);
}

void excactWay(int n){
    if (n < 10){
        cout << n << " ";
        return;
    }
    cout << n % 10 << " ";
    return excactWay(n / 10);
}

void in_xuoi(int n){
    int tmp = reverseNum(n, 0);
    
    excactWay(tmp);
}

int main() {
    in_xuoi(123);
}
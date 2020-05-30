#include <iostream>
using namespace std;

int findLastDigit(){
    long long superLargeNum1, superLargeNum2;
    cin >> superLargeNum1 >> superLargeNum2;

    int result = superLargeNum1 % 10;
    for (long long i=0; i<superLargeNum2; i++){
        result = result * superLargeNum1;
        result = result % 10;
    }
    return result % 10;
}

int main() {
    cout << findLastDigit();
}
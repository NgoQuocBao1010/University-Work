#include <iostream>
using namespace std;

int checkPrime(int n, int checkIn){
    if (checkIn * checkIn > n)
        return true;
    
    if (n % checkIn == 0)
        return false;
    
    return checkPrime(n, checkIn + 2);
}

int nguyento(int n){
    if (n < 2)
        return false;
    
    if (n == 2 || n == 3)
        return true;
    
    if (n % 2 == 0)
        return false;
    
    return checkPrime(n, 3);
}

int main() {
    // in_xuoi(123);
    cout << nguyento(9);
}
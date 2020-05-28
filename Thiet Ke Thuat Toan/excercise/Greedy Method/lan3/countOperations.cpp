#include <iostream>

using namespace std;

long long findMin(long long a, long long b){
    if (a < b)
        return a;
    return b;
}

void countOperations(const char* fileName){
    freopen(fileName, "r", stdin);
    long long size, k;
    cin >> size >> k;

    long long operations = 0;
    for (long long i=0; i<size; i++){
        long long element;
        cin >> element;

        if (element < k) {
            operations += k - element;
        }
        else{
            long long modulo = element % k;
            operations += findMin(modulo, k-modulo);
        }
    }
    cout << operations << endl;
}

int main(){
    countOperations("test.txt");
}
#include <iostream>
#include <algorithm>
using namespace std;

long long maxNum(long long a, long long b){
    if (a > b) return a;
    return b;
}

void findBoundingBox(const char* fileName){
    freopen(fileName, "r", stdin);

    int numberOfHouses;
    cin >> numberOfHouses;

    long long maxY, minY, maxX, minX;

    cin >> maxX;
    cin >> maxY;

    minY = maxY;
    minX = maxX;

    for (int i=1; i<numberOfHouses; i++){
        long long x, y;
        cin >> x;
        cin >> y;

        if (x > maxX) maxX = x;
        else if (x < minX) minX = x;

        if (y > maxY) maxY =y;
        else if (y < minY) minY = y;
    }

    long long side1 = maxY - minY;
    long long side2 = maxX - minX;

    long long result;
    result = maxNum(side1, side2);

    cout << result * result;
}

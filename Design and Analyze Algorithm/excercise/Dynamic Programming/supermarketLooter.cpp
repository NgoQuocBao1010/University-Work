#include <iostream>
#include <algorithm>
using namespace std;

using namespace std;

int solveDP(int weights[], int values[], int items, int capacity, int** mem) {
    if (mem[items][capacity] != -1)
        return mem[items][capacity];
    int result;
    if (items == 0 || capacity == 0)
        result = 0;
    
    else if (weights[items] > capacity) 
        result = solveDP(weights, values, items - 1, capacity, mem);
    
    else {
        int tmp1 = solveDP(weights, values, items - 1, capacity, mem);
        int tmp2 = values[items] + solveDP(weights, values, items - 1, capacity - weights[items], mem);

        if (tmp1 > tmp2)
            result = tmp1;
        
        else 
            result = tmp2;
    }
    mem[items][capacity] = result;
    return result;
}

int knapSack(int weights[], int values[], int items, int capacity) {
    int** mem;
    mem = new int*[items+1];

    for (int i=0; i<=items; i++)
        mem[i] = new int[capacity + 1];
    
    for (int i=0; i<=items; i++) {
        for (int j=0; j<=capacity; j++) {
            mem[i][j] = -1;
        }
    }

    return solveDP(weights, values, items, capacity, mem);
}
 
void solveLooters() {
    int testCases;
    cin >> testCases;

    for (int ca=0; ca<testCases; ca++) {
        int items;
        cin >> items;

        int* values = new int[items+1];
        int* weight = new int[items+1];

        for (int i=1; i<=items; i++) {
            cin >> values[i];
            cin >> weight[i];
        }

        int looters;
        cin >> looters;

        int lootersValue = 0;

        for (int i=0; i<looters; i++) {
            int weightLimit;
            cin >> weightLimit;

            lootersValue += knapSack(weight, values, items, weightLimit);
        }
        cout << lootersValue << endl;
    }
}
  
int main() {
    solveLooters();
    return 0; 
}
#include <iostream>
#include <algorithm>
using namespace std;

#define MINVALUE -100000007

void selectingToys(){
    int numOfToys, numOfBoxes;
    cin >> numOfToys >> numOfBoxes;

    int* selectedToys = new int[numOfBoxes+1];

    for (int i=0; i<numOfBoxes+1; i++)
        selectedToys[i] = MINVALUE;
    
    for (int i=0; i<numOfToys; i++){
        int toysValue, toysBox;
        cin >> toysValue >> toysBox;

        if (selectedToys[toysBox] < toysValue)
            selectedToys[toysBox] = toysValue;
    }

    int result = 0;
    for (int i=0; i<numOfBoxes+1; i++){
        if (selectedToys[i] != MINVALUE)
            result += selectedToys[i];
    }

    cout << result;
}

int main(){
    // freopen("test.txt", "r", stdin);
    // selectingToys();
    cout << "Hello";
}
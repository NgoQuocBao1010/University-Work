#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

#define MAXSIZE 1000

void noNameSchool(){
    int numOfTest;
    cin >> numOfTest;
    int* countArr = new int[numOfTest];

    for (int i=0; i<numOfTest; i++){
        int items;
        cin >> items;
        
        int* itemsContent = new int[items * 2];
        int max = -1;

        for (int i=0; i<items * 2; i++){
            cin >> itemsContent[i];
            if (itemsContent[i] > max) max = itemsContent[i];
        }

        // bool* itemsCount = new bool[max];
        vector <bool> itemsCount;
        // cout << "Da tao!" << ", " << i << endl;

        // memset(itemsCount, false, max + 1);
        for (int i=0; i<=max; i++){
            bool tmp = false;
            itemsCount.push_back(tmp);
        }

        int count = 0;
        for (int i=0; i<items * 2; i++){
            if (!itemsCount[itemsContent[i]]) {
                itemsCount[itemsContent[i]] = true;
                count ++;
            }
        }

        // for (int i=0; i<=max; i++){
        //     cout << itemsCount[i] << "\t";
        // }

        // cout << endl;

        countArr[i] = count;
    }
    for (int i=0; i<numOfTest; i++){
        cout << countArr[i] << endl;
    }
}

int main(){
    noNameSchool();
    // int a[2000];
    // cout << 5;
}
#include <iostream>
#include <stdio.h>
using namespace std;

void isThisAFuckingTree(){
    int numOfNodes;
    cin >> numOfNodes;

    int* levelOfNodes = new int[numOfNodes];

    bool haveLevel1 = false;
    int maxLevel = -1;

    for (int i=0; i<numOfNodes; i++){
        cin >> levelOfNodes[i];

        if (levelOfNodes[i] > maxLevel) maxLevel = levelOfNodes[i];
        if (levelOfNodes[i] == 1) haveLevel1 = true;
    }

    if (!haveLevel1){
        cout << "NO";
        return;
    }

    int* levels = new int[maxLevel + 1];

    for (int i=0; i<maxLevel+1; i++){
        levels[i] = 0;
    }

    for (int i=0; i<numOfNodes; i++){
        int nodesLevel = levelOfNodes[i];
        levels[nodesLevel] += 1;
    }

    int check = 0;
    for (int i=1; i<maxLevel+1; i++){
        check += (i - 2) * levels[i];
    }

    if (check == -2) cout << "YES";
    else cout << "NO";

}

int main(){
    isThisAFuckingTree();
}
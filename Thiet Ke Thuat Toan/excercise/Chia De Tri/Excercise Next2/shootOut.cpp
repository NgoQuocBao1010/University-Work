#include <iostream>
using namespace std;


void shootOut(const char* fileName){
    int numberOfEnemies, numberOfRounds;

    freopen(fileName, "r", stdin);
    cin >> numberOfEnemies;

    int* enemyStrength = new int[numberOfEnemies];

    for (int i=0; i < numberOfEnemies; i++){
        cin >> enemyStrength[i];
    }

    cin >> numberOfRounds;

    int roundStrength[numberOfRounds];

    for (int i=0; i < numberOfRounds; i++){
        cin >> roundStrength[i];
    }

    int enemiesDefeated, damage, strength;
    for (int i=1; i <= numberOfRounds; i++){
        enemiesDefeated = 0;
        damage = 0;
        strength = roundStrength[i - 1];
        
        for (int i=0; i < numberOfEnemies; i++){
            if (strength >= enemyStrength[i]){
                enemiesDefeated ++;
                damage = damage + enemyStrength[i];
            }
        }
        cout << enemiesDefeated << " " << damage << endl;
    }

}

int main() {

}
#include <iostream>
using namespace std;


void atmMachine(){
    int totalMoney;
    cin >> totalMoney;

    if (totalMoney != 0 && totalMoney % 10000 != 0) {
        cout << "KHONG RUT DUOC" << endl;
        return;
    }

    int moneyList[6] = {500000, 200000, 100000, 50000, 20000, 10000};

    int index = 0;
    int numOfToTien;
    while (totalMoney > 0){
        numOfToTien = totalMoney / moneyList[index];

        if (numOfToTien > 0)
            cout << moneyList[index] << " VND: " << numOfToTien << endl;

        totalMoney = totalMoney % moneyList[index];
        index++;
    }
}

int main(){
    atmMachine();
}
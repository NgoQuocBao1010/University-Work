#include <iostream>
#include <vector>
using namespace std;

#define MaxValue 10000007


void countRectangle() {
    vector <vector <int>> matrix;
    vector <vector <int>> result;

    int rows, cols;
    cin >> rows >> cols;

    for (int i=0; i<rows; i++) {
        vector <int> col;
        for (int j=0; j<cols; j++) {
            int element;
            cin >> element;
            col.push_back(element);
        }
        matrix.push_back(col);
        result.push_back(col);
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (i == 0 && j == 0) 
                continue;
            
            if (i == 0) {
                result[i][j] += result[i][j - 1];
            }
            else if (j == 0) {
                result[i][j] += result[i - 1][j];
            }
            else {
                result[i][j] += result[i][j - 1] + result[i - 1][j] - result[i - 1][j - 1];
            }
        }
    }
    int ques, x, y;
    cin >> ques;
    for (int i=0; i<ques; i++) {
        cin >> x >> y;
        cout << result[x - 1][y - 1] << endl;
    }
}

int main() {
    freopen("testInput.txt", "r", stdin);
    countRectangle();
    return 0;
}
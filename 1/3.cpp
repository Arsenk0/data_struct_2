#include <iostream>

using namespace std;

void swapRows(int matrix[5][5], int row1, int row2) {
    for (int i = 0; i < 5; ++i) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}
void swapColumns(int matrix[5][5], int col1, int col2) {
    for (int i = 0; i < 5; ++i) {
        swap(matrix[i][col1], matrix[i][col2]);
    }
}
void printMatrix(int matrix[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[5][5] = {
            {5, 4, 3, 2, 1},
            {10, 9, 8, 7, 6},
            {15, 14, 13, 12, 11},
            {20, 19, 18, 17, 16},
            {25, 24, 23, 22, 21}
    };
    cout << "Початкова матриця:" << endl;
    printMatrix(matrix);

    swapRows(matrix, 0, 1);
    swapColumns(matrix, 0, 1);
    swapRows(matrix, 1, 2);
    swapColumns(matrix, 1, 2);
    swapRows(matrix, 2, 3);
    swapColumns(matrix, 2, 3);
    swapRows(matrix, 3, 4);
    swapColumns(matrix, 3, 4);


    cout << "Матриця після перестановок:" << endl;
    printMatrix(matrix);

    return 0;
}

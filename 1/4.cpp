#include <iostream>

using namespace std;

const int N = 5;

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[N][N];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }


    for (int i = 0; i < N; ++i) {
        matrix[i][i] = 0;
    }

    int maxRow = 0;
    int maxElement = matrix[0][0];
    for (int i = 1; i < N; ++i) {
        if (matrix[i][i] > maxElement) {
            maxElement = matrix[i][i];
            maxRow = i;
        }
    }

    for (int i = maxRow; i < N - 1; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = matrix[i + 1][j];
        }
    }

    cout << "matrix pislya delete:" << endl;
    printMatrix(matrix);

    return 0;
}

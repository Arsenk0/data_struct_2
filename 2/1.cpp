#include <iostream>
using namespace std;

bool MultipleOfFour(int n) {
    return n % 4 == 0;
}

void inputArray(double arr[], int n) {
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}
void printArray(double arr[], int n) {
    cout << "Array elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void createMatrix(double arr[], int n) {
    if (!MultipleOfFour(n)) {
        cout << "Array size must be a multiple of 4." << endl;
        return;
    }

    int rows = n / 4;
    double matrix[rows][4];

    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = arr[index++];
        }
    }

    for (int i = 0; i < rows; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < 4; ++j) {
                for (int k = j + 1; k < 4; ++k) {
                    if (matrix[i][j] > matrix[i][k]) {
                        swap(matrix[i][j], matrix[i][k]);
                    }
                }
            }
        } else {
            for (int j = 0; j < 4; ++j) {
                for (int k = j + 1; k < 4; ++k) {
                    if (matrix[i][j] < matrix[i][k]) {
                        swap(matrix[i][j], matrix[i][k]);
                    }
                }
            }
        }
    }
}
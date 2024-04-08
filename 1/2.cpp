#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void remove(int array[], int& n, int x) {
    int i = 0;
    while (i < n) {
        if (array[i] <= x) {
            for (int j = i; j < n - 1; ++j) {
                array[j] = array[j + 1];
            }
            array[n - 1] = 0;
            --n;
        } else {
            ++i;
        }
    }
}

int main() {
    int n, x;
    cout << "vvedit rozmir arr: ";
    cin >> n;

    int A[n];
    srand(time(0));


    for (int i = 0; i < n; ++i) {
        int num;
        bool unique;

        do {
            num = rand() % 100;
            unique = true;

            for (int j = 0; j < i; ++j) {
                if (A[j] == num) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);

        A[i] = num;
    }

    cout << "arr pislya generation:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Vvedit X: ";
    cin >> x;

    remove(A, n, x);

    cout << "arr pislya del elements, - or == " << x << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

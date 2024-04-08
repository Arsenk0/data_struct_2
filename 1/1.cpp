#include <iostream>
using namespace std;
void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void custom(int arr[], int n) {
    int odd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            swap(arr[i], arr[odd]);
            odd++;
        }
    }

    bubble(arr, odd);
    bubble(arr + odd, n - odd);
}

int main() {
    int arr[] = {5, 8, 9, 6, 7, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    custom(arr, n);

    cout << "zmineniy arr: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct worker {
    string surname;
    string initials;
    string position;
    int startYear;
    double salary;

    int experience() {
        int currentYear = 2024;
        return currentYear - startYear;
    }

    double salaryWithTax() {
        const double taxRate = 0.33;
        return salary * (1 - taxRate);
    }
};

int main() {
    int n;
    cout << "Введіть кількість працівників: ";
    cin >> n;

    worker workers[n];

    for (int i = 0; i < n; ++i) {
        cout << "Працівник " << i + 1 << ":\n";
        cout << "Прізвище: ";
        cin >> workers[i].surname;
        cout << "Ініціали: ";
        cin >> workers[i].initials;
        cout << "Посада: ";
        cin >> workers[i].position;
        cout << "Рік вступу на роботу: ";
        cin >> workers[i].startYear;
        cout << "Зарплата: ";
        cin >> workers[i].salary;
    }

    cout << "\nІнформація про працівників:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Працівник " << i + 1 << ":\n";
        cout << "Прізвище: " << workers[i].surname << "\n";
        cout << "Ініціали: " << workers[i].initials << "\n";
        cout << "Посада: " << workers[i].position << "\n";
        cout << "Стаж роботи: " << workers[i].experience() << " років\n";
        cout << "Зарплата (з урахуванням податку): " << workers[i].salaryWithTax() << "\n";
        cout << "-------------------------\n";
    }

    return 0;
}

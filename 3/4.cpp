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
    cout << "������ ������� ����������: ";
    cin >> n;

    worker workers[n];

    for (int i = 0; i < n; ++i) {
        cout << "��������� " << i + 1 << ":\n";
        cout << "�������: ";
        cin >> workers[i].surname;
        cout << "�������: ";
        cin >> workers[i].initials;
        cout << "������: ";
        cin >> workers[i].position;
        cout << "г� ������ �� ������: ";
        cin >> workers[i].startYear;
        cout << "��������: ";
        cin >> workers[i].salary;
    }

    cout << "\n���������� ��� ����������:\n";
    for (int i = 0; i < n; ++i) {
        cout << "��������� " << i + 1 << ":\n";
        cout << "�������: " << workers[i].surname << "\n";
        cout << "�������: " << workers[i].initials << "\n";
        cout << "������: " << workers[i].position << "\n";
        cout << "���� ������: " << workers[i].experience() << " ����\n";
        cout << "�������� (� ����������� �������): " << workers[i].salaryWithTax() << "\n";
        cout << "-------------------------\n";
    }

    return 0;
}

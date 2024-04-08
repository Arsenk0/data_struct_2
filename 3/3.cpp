#include <iostream>
#include <string>

using namespace std;

struct abiturient {
    string surname;
    string name;
    string address;
    double znoMath;
    double znoUkrainian;
    double znoPhysics;
};


double calculateAverageZNO(double math, double ukrainian, double physics) {
    return (math + ukrainian + physics) / 3.0;
}

int main() {
    const int n = 3;
    const double passingGrade = 150.0;

    abiturient abiturients[n];

    for (int i = 0; i < n; ++i) {
        cout << "������� #" << i + 1 << endl;
        cout << "�������: ";
        cin >> abiturients[i].surname;
        cout << "��'�: ";
        cin >> abiturients[i].name;
        cout << "������: ";
        cin >> abiturients[i].address;
        cout << "������ � ����������: ";
        cin >> abiturients[i].znoMath;
        cout << "������ � ��������� ����: ";
        cin >> abiturients[i].znoUkrainian;
        cout << "������ � ������: ";
        cin >> abiturients[i].znoPhysics;
        cout << endl;
    }

    cout << "��������, �� ��������� � ���:" << endl;
    for (int i = 0; i < n; ++i) {
        double averageZNO = calculateAverageZNO(abiturients[i].znoMath, abiturients[i].znoUkrainian, abiturients[i].znoPhysics);
        if (averageZNO >= passingGrade) {
            cout << "�������: " << abiturients[i].surname << endl;
            cout << "��'�: " << abiturients[i].name << endl;
            cout << "������: " << abiturients[i].address << endl;
            cout << "������� ��� ���: " << averageZNO << endl;
            cout << endl;
        }
    }

    return 0;
}

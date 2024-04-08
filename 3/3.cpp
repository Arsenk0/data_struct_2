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
        cout << "Абітурієнт #" << i + 1 << endl;
        cout << "Прізвище: ";
        cin >> abiturients[i].surname;
        cout << "Ім'я: ";
        cin >> abiturients[i].name;
        cout << "Адреса: ";
        cin >> abiturients[i].address;
        cout << "Оцінка з математики: ";
        cin >> abiturients[i].znoMath;
        cout << "Оцінка з української мови: ";
        cin >> abiturients[i].znoUkrainian;
        cout << "Оцінка з фізики: ";
        cin >> abiturients[i].znoPhysics;
        cout << endl;
    }

    cout << "Абітурієнти, які поступили у ВНЗ:" << endl;
    for (int i = 0; i < n; ++i) {
        double averageZNO = calculateAverageZNO(abiturients[i].znoMath, abiturients[i].znoUkrainian, abiturients[i].znoPhysics);
        if (averageZNO >= passingGrade) {
            cout << "Прізвище: " << abiturients[i].surname << endl;
            cout << "Ім'я: " << abiturients[i].name << endl;
            cout << "Адреса: " << abiturients[i].address << endl;
            cout << "Середній бал ЗНО: " << averageZNO << endl;
            cout << endl;
        }
    }

    return 0;
}

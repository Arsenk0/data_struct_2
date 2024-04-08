#include <iostream>
#include <string>

using namespace std;

struct Student {
    string last_name;
    string first_name;
    double scholarship_amount;
    int hours_absent;
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n];

    for (int i = 0; i < n; ++i) {
        cout << "Student #" << i + 1 << ":\n";
        cout << "Last Name: ";
        cin >> students[i].last_name;
        cout << "First Name: ";
        cin >> students[i].first_name;
        cout << "Scholarship Amount: ";
        cin >> students[i].scholarship_amount;
        cout << "Number of Absent Hours: ";
        cin >> students[i].hours_absent;
    }

    cout << "\nStudents receiving scholarships and having no more than 2 absent hours:\n";
    int total_absent_hours = 0;
    for (int i = 0; i < n; ++i) {
        if (students[i].scholarship_amount > 0 && students[i].hours_absent <= 2) {
            cout << students[i].last_name << " " << students[i].first_name << "\n";
            total_absent_hours += students[i].hours_absent;
        }
    }

    cout << "\nTotal absent hours: " << total_absent_hours << "\n";

    return 0;
}

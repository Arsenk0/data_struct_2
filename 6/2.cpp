#include <iostream>
#include <string>

using namespace std;

struct Car {
    string name;
    int year;
    double price;
    Car* next;
};

void addCar(Car*& head, string name, int year, double price) {
    Car* newCar = new Car;
    newCar->name = name;
    newCar->year = year;
    newCar->price = price;
    newCar->next = nullptr;

    if (head == nullptr) {
        head = newCar;
    } else {
        Car* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newCar;
    }
}

void printCars(Car* head) {
    Car* current = head;
    while (current != nullptr) {
        cout << "Назва: " << current->name << ", Рік випуску: " << current->year
             << ", Ціна: " << current->price << " у.о." << endl;
        current = current->next;
    }
}

void free(Car*& head) {
    while (head != nullptr) {
        Car* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Car* carList = nullptr;


    addCar(carList, "Koenigseq", 2015, 4500);
    addCar(carList, "Lotus ", 2010, 3500);
    addCar(carList, "Lamborghini", 2008, 3000);
    addCar(carList, "Bugatti", 2012, 4800);

    cout << "Список автомобілів:" << endl;
    printCars(carList);

    free(carList);

    return 0;
}

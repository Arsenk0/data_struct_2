#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_set>

using namespace std;

struct ST {
    int data;
    ST* next;
};

void append(ST*& head, int value) {
    ST* newNode = new ST;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        ST* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void printUniqueValues(ST* head) {
    unordered_set<int> uniqueValues;
    ST* current = head;
    while (current != nullptr) {
        if (uniqueValues.find(current->data) == uniqueValues.end()) {
            uniqueValues.insert(current->data);
            cout << current->data << " ";
        }
        current = current->next;
    }
    cout << endl;
}

void removeEvenElements(ST*& head) {
    ST* current = head;
    ST* prev = nullptr;
    while (current != nullptr) {
        if (current->data % 2 == 0) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            current = prev;
        }
        prev = current;
        current = current->next;
    }
}

void freeMemory(ST*& head) {
    while (head != nullptr) {
        ST* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ST* myList = nullptr;
    srand(time(nullptr));

  
    for (int i = 0; i < 10; ++i) {
        append(myList, rand() % 100);
    }

    cout << "Список унікальних значень: ";
    printUniqueValues(myList);

    removeEvenElements(myList);
    cout << "Список після видалення парних елементів: ";
    printUniqueValues(myList);

    freeMemory(myList);
    return 0;
}

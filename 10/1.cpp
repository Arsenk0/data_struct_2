#include <iostream>
#include <string>

using namespace std;

struct Temperature {
    float value;
    int time;
    string model;
    string location;
};

struct Tree {
    Temperature data;
    Tree* left;
    Tree* right;

    Tree(const Temperature& temp)
            : data(temp), left(nullptr), right(nullptr) {}
};

class TemperatureBST {
public:
    TemperatureBST() : root(nullptr) {}

    void insert(const Temperature& temp) {
        root = insertNode(root, temp);
    }

    float averageTemperatureByLocation(const string& location) {
        int count = 0;
        float totalTemperature = 0.0;
        computeAverageTemperature(root, location, count, totalTemperature);
        return count > 0 ? totalTemperature / count : 0.0;
    }

private:
    Tree* root;

    Tree* insertNode(Tree* node, const Temperature& temp) {
        if (node == nullptr) {
            return new Tree(temp);
        }

        if (temp.value < node->data.value) {
            node->left = insertNode(node->left, temp);
        } else {
            node->right = insertNode(node->right, temp);
        }

        return node;
    }

    void computeAverageTemperature(Tree* node, const string& location, int& count, float& totalTemperature) {
        if (node == nullptr) {
            return;
        }

        computeAverageTemperature(node->left, location, count, totalTemperature);

        if (node->data.location == location) {
            totalTemperature += node->data.value;
            count++;
        }

        computeAverageTemperature(node->right, location, count, totalTemperature);
    }
};

int main() {
    TemperatureBST bst;

    char choice;
    do {
        Temperature temp;

        cout << "Enter temperature value: ";
        cin >> temp.value;

        cout << "Enter hour of measurement: ";
        cin >> temp.time;

        cout << "Enter thermometer model: ";
        cin >> temp.model;

        cout << "Enter location: ";
        cin.ignore();
        getline(cin, temp.location);

        bst.insert(temp);

        cout << "Do you want to enter another measurement? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    string locationToAverage;
    cout << "Enter location to calculate average temperature: ";
    cin.ignore();
    getline(cin, locationToAverage);

    cout << "Average temperature in " << locationToAverage << " location: "
         << bst.averageTemperatureByLocation(locationToAverage) << endl;

    return 0;
}

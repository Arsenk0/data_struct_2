#include <iostream>
#include <cmath>
using namespace std;

struct Triangle {
    double a;
    double b;
    double c;
};

double area(const Triangle& t) {
    double s = (t.a + t.b + t.c) / 2.0;
    return sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));
}

int main() {
    Triangle triangle1 = {3.0, 4.0, 5.0};
    Triangle triangle2 = {5.0, 6.0, 7.0};

    double area1 = area(triangle1);
    double area2 = area(triangle2);

    double totalArea = area1 + area2;

    cout << "Area of the first triangle: " << area1 << endl;
    cout << "Area of the second triangle: " << area2 << endl;
    cout << "The sum of the areas of two triangles: " << totalArea << endl;

    return 0;
}

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double xValue = 1.0, double yValue = 1.0) : x(xValue), y(yValue) {
        cout << "[Constructor] Point(" << x << ", " << y << ") created." << endl;
        system("pause");
    }

    ~Point() {
        cout << "[Destructor] Point(" << x << ", " << y << ") destroyed." << endl;
        system("pause");
    }

    void setCoordinates(double xValue, double yValue) {
        x = xValue;
        y = yValue;
    }

    void input() {
        cin >> x >> y;
    }

    double distanceTo(const Point& other) const {
        const double dx = x - other.x;
        const double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

class Triangle {
private:
    Point a;
    Point b;
    Point c;

public:
    Triangle() {
        cout << "[Constructor] Triangle created." << endl;
        system("pause");
    }

    ~Triangle() {
        cout << "[Destructor] Triangle destroyed." << endl;
        system("pause");
    }

    void inputVertices() {
        cout << "Please input three vertices (x y for each point):" << endl;
        cout << "Vertex A: ";
        a.input();
        cout << "Vertex B: ";
        b.input();
        cout << "Vertex C: ";
        c.input();
    }

    double perimeter() const {
        return a.distanceTo(b) + b.distanceTo(c) + c.distanceTo(a);
    }

    double area() const {
        const double ab = a.distanceTo(b);
        const double bc = b.distanceTo(c);
        const double ca = c.distanceTo(a);
        const double semi = (ab + bc + ca) / 2.0;
        const double areaValue = semi * (semi - ab) * (semi - bc) * (semi - ca);
        return areaValue > 0.0 ? sqrt(areaValue) : 0.0;
    }

    vector<double> sideLengths() const {
        vector<double> sides = {a.distanceTo(b), b.distanceTo(c), c.distanceTo(a)};
        sort(sides.begin(), sides.end());
        return sides;
    }
};

bool areCongruent(const Triangle& first, const Triangle& second) {
    const vector<double> firstSides = first.sideLengths();
    const vector<double> secondSides = second.sideLengths();
    const double eps = 1e-6;

    for (size_t i = 0; i < firstSides.size(); ++i) {
        if (fabs(firstSides[i] - secondSides[i]) > eps) {
            return false;
        }
    }
    return true;
}

/*
    Explanation required by the experiment:
    1. When a Triangle object is created, its member objects a, b, and c (Point objects)
       are constructed before the Triangle constructor body runs. This is why Point
       constructor messages appear before the Triangle constructor message.
    2. For two Triangle objects in main, the one defined first is constructed first.
    3. During destruction, the order is reversed:
       - The Triangle destructor body runs first.
       - Then its member objects c, b, and a are destroyed in reverse declaration order.
       - Objects in main are also destroyed in reverse order of creation.
*/

int main() {
    cout << fixed << setprecision(2);

    Triangle triangle1;
    Triangle triangle2;

    cout << "\nInput data for triangle 1:" << endl;
    triangle1.inputVertices();

    cout << "\nInput data for triangle 2:" << endl;
    triangle2.inputVertices();

    cout << "\nTriangle 1 perimeter: " << triangle1.perimeter() << endl;
    cout << "Triangle 1 area: " << triangle1.area() << endl;

    cout << "\nTriangle 2 perimeter: " << triangle2.perimeter() << endl;
    cout << "Triangle 2 area: " << triangle2.area() << endl;

    if (areCongruent(triangle1, triangle2)) {
        cout << "\nThe two triangles are congruent." << endl;
    } else {
        cout << "\nThe two triangles are not congruent." << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point(int xValue = 0, int yValue = 0) : x(xValue), y(yValue) {}

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator+(int value) const {
        return Point(x + value, y + value);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    Point operator-(int value) const {
        return Point(x - value, y - value);
    }

    friend ostream& operator<<(ostream& out, const Point& point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }
};

int main() {
    Point p1(2, 3);
    Point p2(5, 7);
    Point p3(-1, 4);

    Point sum1 = p1 + p2;
    Point sum2 = p1 + 10;
    Point diff1 = p2 - p1;
    Point diff2 = p3 - 2;
    Point mixed = (p1 + p3) - 1;

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "p1 + p2 = " << sum1 << endl;
    cout << "p1 + 10 = " << sum2 << endl;
    cout << "p2 - p1 = " << diff1 << endl;
    cout << "p3 - 2 = " << diff2 << endl;
    cout << "(p1 + p3) - 1 = " << mixed << endl;

    return 0;
}

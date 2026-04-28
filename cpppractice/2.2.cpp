#include <iomanip>
#include <iostream>

using namespace std;

class Vector {
private:
    int rows;
    int* data;

public:
    explicit Vector(int dimension = 0) : rows(dimension), data(nullptr) {
        if (rows > 0) {
            data = new int[rows]{};
        }
    }

    ~Vector() {
        delete[] data;
    }

    Vector(const Vector& other) : rows(other.rows), data(nullptr) {
        if (rows > 0) {
            data = new int[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = other.data[i];
            }
        }
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data;
        rows = other.rows;
        data = nullptr;

        if (rows > 0) {
            data = new int[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    void input() {
        for (int i = 0; i < rows; ++i) {
            cin >> data[i];
        }
    }

    void output() const {
        cout << "[ ";
        for (int i = 0; i < rows; ++i) {
            cout << data[i];
            if (i != rows - 1) {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }

    Vector add(const Vector& other) const {
        if (rows != other.rows) {
            cout << "Cannot add vectors with different dimensions." << endl;
            return Vector();
        }

        Vector result(rows);
        for (int i = 0; i < rows; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    int dot(const Vector& other) const {
        if (rows != other.rows) {
            cout << "Cannot calculate dot product for vectors with different dimensions." << endl;
            return 0;
        }

        int result = 0;
        for (int i = 0; i < rows; ++i) {
            result += data[i] * other.data[i];
        }
        return result;
    }
};

int main() {
    cout << "Input 8 integers for V1:" << endl;
    Vector V1(8);
    V1.input();

    cout << "Input 8 integers for V2:" << endl;
    Vector V2(8);
    V2.input();

    Vector V3;
    V3 = V1.add(V2);

    cout << "\nV1 = ";
    V1.output();
    cout << "V2 = ";
    V2.output();
    cout << "V3 = V1 + V2 = ";
    V3.output();
    cout << "V1 dot V2 = " << V1.dot(V2) << endl;

    cout << "\nInput 6 integers for pV1:" << endl;
    Vector* pV1 = new Vector(6);
    pV1->input();

    cout << "Input 6 integers for pV2:" << endl;
    Vector* pV2 = new Vector(6);
    pV2->input();

    Vector* pV3 = new Vector(6);
    *pV3 = pV1->add(*pV2);

    cout << "\npV1 = ";
    pV1->output();
    cout << "pV2 = ";
    pV2->output();
    cout << "pV3 = pV1 + pV2 = ";
    pV3->output();
    cout << "pV1 dot pV2 = " << pV1->dot(*pV2) << endl;

    delete pV1;
    delete pV2;
    delete pV3;

    return 0;
}

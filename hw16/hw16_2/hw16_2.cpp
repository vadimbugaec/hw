#include <iostream>
#include <cmath>

using namespace std;

class Vector2d {
private:
    double x;
    double y;

public:
    Vector2d(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Vector2d& operator=(const Vector2d& other);
    Vector2d operator+(const Vector2d& secondVector) const;
    Vector2d operator-(const Vector2d& secondVector) const;
    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

    double operator()() const;
    double& operator[](int i);

    void printVector() const;

    void inputVector();

    friend istream& operator>>(istream& is, Vector2d& v);

    friend ostream& operator<<(ostream& os, const Vector2d& v);
};

Vector2d& Vector2d::operator=(const Vector2d& other) {
    if (this == &other) {
        return *this;
    }
    x = other.x;
    y = other.y;
    return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) const {
    return Vector2d(x + secondVector.x, y + secondVector.y);
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) const {
    return Vector2d(x - secondVector.x, y - secondVector.y);
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
    return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

double Vector2d::operator()() const {
    return sqrt(x * x + y * y);
}

double& Vector2d::operator[](int i) {
    if (i == 0) return x;
    if (i == 1) return y;
    throw out_of_range("Index out of range");
}

void Vector2d::printVector() const {
    cout << "{" << x << "; " << y << "}";
}

void Vector2d::inputVector() {
    cout << "Enter vector coordinates (x y): ";
    cin >> x >> y;
}

istream& operator>>(istream& is, Vector2d& v) {
    is >> v.x >> v.y;
    return is;
}

ostream& operator<<(ostream& os, const Vector2d& v) {
    os << "{" << v.x << "; " << v.y << "}";
    return os;
}

int main() {
    Vector2d testVec{ 1.2, 5.6 };
    cout << "Test Vector: " << testVec << endl;

    Vector2d v1(1.0, 2.0);
    Vector2d v2(3.0, 4.0);

    Vector2d v3 = v1 + v2;
    Vector2d v4 = v1 - v2;

    cout << "v1 + v2: " << v3 << endl;
    cout << "v1 - v2: " << v4 << endl;

    cout << "Vector length of testVec: " << testVec() << endl;

    testVec[0] = 10.0;
    testVec[1] = 20.0;
    cout << "Updated testVec: " << testVec << endl;

    Vector2d inputVec;
    inputVec.inputVector();
    cout << "Inputted Vector: " << inputVec << endl;

    return 0;
}

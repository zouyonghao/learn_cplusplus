#include <iostream>
using namespace std;
class Complex {
private:
    double real, imag;
public:
    Complex(double r, double i):real(r), imag(i) { }
    Complex operator+(double r);
    friend Complex operator+(double r, Complex & c);
    void print() {
        cout << real << ", " << imag << endl;
    }
};

Complex Complex::operator+(double r) {
    return Complex(real + r, imag);
}

Complex operator+(double r, Complex & c) {
    return Complex(r + c.real, c.imag);
}

int main() {
    Complex c1(1, 2);
    double r = 3.0;
    c1 = c1 + r;
    c1 = r + c1;
    c1.print();
    return 0;
}
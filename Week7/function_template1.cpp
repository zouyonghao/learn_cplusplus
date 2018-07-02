#include <iostream>
using namespace std;

template<class T>
void Swap(T & a, T & b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 1, b = 2;
    double c = 3.1, d = 4.5;
    Swap(a, b);
    cout << a << " " << b << endl;
    Swap(c, d);
    cout << c << " " << d << endl;
    return 0;
}
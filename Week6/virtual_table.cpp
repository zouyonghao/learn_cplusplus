#include <iostream>
using namespace std;

class Base {
public:
    int i;
    virtual void Print() {
        i = 1;
        cout << "Base::Print" << endl;
    }
};

class Derived:virtual public Base {
public:
    int n;
    virtual void Print() {
        n = 2;
        cout << "Derived::Print" << endl;
    }
};

int main() {
    Derived d;
    d.Print();
    d.Base::Print();
    cout << d.n << ", " << d.i << endl;

    cout << sizeof(d) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(Base) << ", " << sizeof(Derived) << endl;
    return 0;
}
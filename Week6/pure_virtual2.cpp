#include <iostream>
using namespace std;

class A {
public:
    virtual void f() = 0;
    void g() {
        f();
    }
    A () {
        // f(); // err. pure virtual xxx called from constructor
    }
};

class B:public A {
public:
    void f() {
        cout << "B::f" << endl;
    }
};

int main() {
    B b;
    b.f();
    b.g();
    return 0;
}
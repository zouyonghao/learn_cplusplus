#include <iostream>
using namespace std;
class Base {
private:
    int n;
public:
    Base(int i):n(i) {
        cout << "Base " << n << " constructed" << endl;
    }
    ~Base() {
        cout << "Base " << n << " destructed" << endl;
    }
};
class Derived:public Base {
public:
    Derived():Base(4) {
        cout << "Derived constructed" << endl;
    }
    ~Derived() {
        cout << "Derived destructed" << endl;
    }
};
class MoreDerived:public Derived {
public:
    MoreDerived():Derived() {
        cout << "MoreDerived constructed" << endl;
    }
    ~MoreDerived() {
        cout << "MoreDerived destructed" << endl;
    }
};

int main() {
    MoreDerived obj;
    return 0;
}
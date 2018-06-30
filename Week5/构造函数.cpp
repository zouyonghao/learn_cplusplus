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
    Derived(int i):Base(i) {
        cout << "Derived constructed" << endl;
    }
    ~Derived() {
        cout << "Derived destructed" << endl;
    }
};
int main() {
    Derived obj(3);
    return 0;
}
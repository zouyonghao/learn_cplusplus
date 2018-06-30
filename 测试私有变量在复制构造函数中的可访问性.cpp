#include <iostream>

class A {
private:
    int a;
public:
    A (int aa):a(aa) { }
    A (A & a2) {
        a = a2.a;
    }
    int getA() {
        return a;
    }
};

int main() {
    A a(10);
    A a2(a);
    std::cout << a2.getA() << std::endl;
    return 0;
}
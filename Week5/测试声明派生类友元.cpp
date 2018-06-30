#include <iostream>
using namespace std;

class derived;

class base {
private:
    int i;
    friend void derived::access();
};
class derived:public base {
private:
    int j;
public:
    void access();
};
void derived::access() {
    j = 1;
}

int main() {
    derived d;
    d.access();
    return 0;
}
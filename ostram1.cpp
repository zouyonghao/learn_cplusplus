#include <iostream>
using namespace std;
class CStudent {
public:
    int nAge;
};

ostream & operator<<(ostream & o, const CStudent & s) {
    o << s.nAge;
    return o;
}

int main() {
    CStudent s;
    s.nAge = 10;
    cout << s << "hello";
    return 0;
}
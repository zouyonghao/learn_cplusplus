#include <iostream>
using namespace std;
class CDemo {
private:
    int n;
public:
    CDemo(int nn = 0):n(nn) { }
    // friend ostream & operator<<(ostream & os, const CDemo & d);
    
    CDemo operator++(int) {
        CDemo tmp(*this);
        n++;
        return tmp;
    }
    CDemo & operator++() {
        n++;
        return * this;
    }

    friend CDemo operator--(CDemo & c, int);
    friend CDemo & operator--(CDemo & c);
    operator int () {
        return n;
    }
};

// ostream & operator<<(ostream & os, const CDemo & c) {
//     os << c.n;
//     return os;
// }

CDemo operator--(CDemo & c, int) {
    CDemo tmp(c.n);
    c.n++;
    return tmp;
}

CDemo & operator--(CDemo & c) {
    c.n++;
    return c;
}

int main() {
    CDemo d(5);
    cout << (d++) << ",";
    cout << d << ",";
    cout << (++d) << ",";
    cout << d << endl;
    cout << (d--) << ",";
    cout << d << ",";
    cout << (--d) << ",";
    cout << d << endl;
    return 0;
}

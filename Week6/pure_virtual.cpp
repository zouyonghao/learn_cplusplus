#include <iostream>
using namespace std;

class CShape {
public:
    virtual int Area() = 0;
};

class CRectangle:public CShape {
    int Area() {
        cout << "CRectangle::Area" << endl;
        return 0;
    }
};

int main() {
    CRectangle r;
    CShape * cs = & r;
    cs->Area();
    return 0;
}
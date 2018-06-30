#include <iostream>
#include <cstring>
using namespace std;
class CArray {
private:
    int size;
    int * ptr;
public:
    CArray(int s = 0.0);
    CArray(const CArray & c);
    void push_back(int i);
    int & operator[](int i) {
        return ptr[i];
    }
    int length() {
        return size;
    }
    CArray & operator=(const CArray & a);
};
CArray::CArray(int s):size(s) {
    if (s == 0) {
        ptr = NULL;
        return;
    }
    ptr = new int[s];
}

CArray::CArray(const CArray & c) {
    if (0 == c.size) {
        size = 0;
        ptr = NULL;
        return;
    }
    ptr = new int[c.size];
    memcpy(ptr, c.ptr, sizeof(int) * c.size);
    size = c.size;
}

void CArray::push_back(int i) {
    if (ptr) {
        int * tmpPtr = new int[size + 1];
        memcpy(tmpPtr, ptr, sizeof(int) * size);
        delete ptr;
        ptr = tmpPtr;
    } else {
        ptr = new int[1];
    }
    ptr[size++] = i;
}

CArray & CArray::operator=(const CArray & a) {
    if (a.ptr == ptr) {
        return * this;
    }
    if (!a.ptr) {
        if (ptr) {
            delete [] ptr;
        }
        ptr = NULL;
        size = 0;
        return * this;
    }
    if (size < a.size) {
        if (ptr) {
            delete [] ptr;
        }
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return * this;
}

int main() {
    CArray a;
    for (int i = 0; i < 5; i++) {
        a.push_back(i);
    }
    CArray a2, a3;
    a2 = a;
    for (int i = 0; i < a.length(); ++i) {
        cout << a2[i] << " ";
    }
    a2 = a3; // a2是空的
    for (int i = 0; i < a2.length(); ++i) { // a2.length() 返回0
        cout << a2[i] << " ";
    }
    cout << endl;
    a[3] = 100;
    CArray a4(a);
    for (int i = 0; i < a4.length(); ++i) {
        cout << a4[i] << " ";
    }
    cout << endl;
    return 0;
}

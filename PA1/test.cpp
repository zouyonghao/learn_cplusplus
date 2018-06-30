#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char * str;
public:
    String ():str(NULL) { };
    const char * operator = (const char * s);
    ~String();
    const char * c_str() {
        return str;
    }
};

const char * String::operator = (const char * s) {
    if (str) delete [] str;
    if (s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    } else {
        str = NULL;
    }
    return str;
}

String::~String() {
    delete [] str;
}

int main() {
    String s;
    s = "Good Luck,";
    cout << s.c_str() << endl;
    s = "Shenzhou 8!";
    cout << s.c_str() << endl;
    return 0;
}
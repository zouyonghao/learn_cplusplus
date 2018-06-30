#include <iostream>
using namespace std;

string trim(string c) {
    // trim 0
    for (int i = 0; i < c.length() - 1; i++) {
        if (c[i] == '0') {
            c = c.substr(i + 1);
        } else {
            break;
        }
    }
    return c;
}

int main() {
    string s = "123456";
    cout << s.c_str()[0];
    cout << endl;
    // s.insert(0, "-");
    // cout << s << endl;
    cout << s.substr(0, 3) << endl;
    cout << s.substr(3, 1) << endl;
    string c = "000111000";
    cout << trim(c) << endl;
    return 0;
}
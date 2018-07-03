#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    int dotPos = str.find('.');
    cout << str.substr(0, dotPos);
    string afterDot = str.substr(dotPos + 1, 5);
    if (dotPos < 0) {
        cout << "." << "00000" << endl;
    } else if (afterDot.size() < 5) {
        cout << "." << afterDot << string(5 - afterDot.size(), '0') << endl;
    } else {
        if (str.substr(dotPos + 1)[5] >= '5') {
            afterDot[4] += 1;
        }
        cout << "." << afterDot << endl;
    }
    double d;
    d = stod(str);
    printf("%.07e", d);
    return 0;
}
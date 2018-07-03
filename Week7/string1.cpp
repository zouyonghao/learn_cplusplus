#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s1("good "), s2("morning");
    s1 += s2;
    cout << s1 << endl;
    s2.append(s1, 3, s1.size());
    cout << s2 << endl;
    return 0;
}
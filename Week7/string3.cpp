#include <cstring>
#include <iostream>
using namespace std;

int main() {
    string s1("hello worlld");
    cout << s1.find("ll") << endl;
    cout << s1.find("abc") << endl;
    cout << s1.rfind("ll") << endl;
    cout << s1.rfind("abc") << endl;
    cout << s1.find_first_of("abcde") << endl;
    cout << s1.find_first_of("abc") << endl;
    cout << s1.find_last_of("abcde") << endl;
    cout << s1.find_last_of("abc") << endl;
    cout << s1.find_first_not_of("abcde") << endl;
    cout << s1.find_first_not_of("hello world") << endl;
    cout << s1.find_last_not_of("abcde") << endl;
    cout << s1.find_last_not_of("hello world") << endl;
}
#include <iostream>
using namespace std;

int main() {
    string s("hello world");
    s.replace(2, 3, "haha");
    cout << s << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a = "Helaaalo";
    cout << a.find('l', 0) << endl;
    cout << a.substr(1, 2) << endl;
    return 0;
}
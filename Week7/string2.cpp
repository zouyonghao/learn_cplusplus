#include <iostream>
using namespace std;
int main() {
    string s1("hello"), s2("hello"), s3("hell");
    int f1 = s1.compare(s2);
    int f2 = s1.compare(s3);
    int f3 = s3.compare(s1);
    int f4 = s1.compare(1, 2, s3, 0, 3);   // s1 1-2; s3 0-3
    int f5 = s1.compare(0, s1.size(), s3); // s1 0-end
    cout << f1 << endl << f2 << endl << f3 << endl;
    cout << f4 << endl << f5 << endl;
}
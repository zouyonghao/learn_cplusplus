#include <iostream>
using namespace std;

template<class T1, class T2>
void Print(T1 arg1, T2 arg2) {
    cout << "Print(T1, T2)" << endl;
    cout << arg1 << " " << arg2 << endl;
}

template<class T>
void Print(T arg1, T arg2) {
    cout << "Print(T, T)" << endl;
    cout << arg1 << " " << arg2 << endl;
}

int main() {
    int a = 1, b = 2;
    double c = 3.4;
    Print(a, b);
    Print(a, c);
    return 0;
}
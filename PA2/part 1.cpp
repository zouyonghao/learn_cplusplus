// #include <iostream>
// #include <cstring>
// #include <cstdlib>
// using namespace std;
// class Complex {
// private:
//     double r,i;
// public:
//     void Print() {
//         cout << r << "+" << i << "i" << endl;
//     }
// 在此处补充你的代码
    Complex & operator=(string str) {
        int pos = str.find('+', 0);
        r = atof(str.substr(0, pos).c_str());
        i = atof(str.substr(pos + 1, str.length() - pos - 2).c_str());
    }
// };
// int main() {
//     Complex a;
//     a = "3+4i"; a.Print();
//     a = "5+6i"; a.Print();
//     return 0;
// }
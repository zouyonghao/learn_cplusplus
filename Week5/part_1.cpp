#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// 在此处补充你的代码
class MyString {
private:
    string str;
public:
    MyString() { }
    MyString(string _str):str(_str) { }
    MyString(const char * _str):str(_str) { }
    friend ostream & operator<<(ostream & os, const MyString &);
    MyString operator+(const MyString &);
    bool operator==(const MyString &);
    bool operator>(const MyString &);
    bool operator<(const MyString &);
    char & operator[](int n) {
        return str[n];
    }
    friend MyString operator+(const string str, const MyString &);
    MyString & operator+=(const MyString & b) {
        str += b.str;
        return * this;
    }
    string operator()(int i, int j) {
        return str.substr(i, j);
    }
};

ostream & operator<<(ostream & os, const MyString & b) {
    os << b.str;
    return os;
}

MyString MyString::operator+(const MyString & b) {
    return MyString(str + b.str);
}

bool MyString::operator==(const MyString & b) {
    return str == b.str;
}

bool MyString::operator>(const MyString & b) {
    return str > b.str;
}

bool MyString::operator<(const MyString & b) {
    return str < b.str;
}

MyString operator+(const string str, const MyString & b) {
    return MyString(str + b.str);
}


int CompareString( const void * e1, const void * e2) {
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( *s1 < *s2 )     return -1;
    else if( *s1 == *s2 ) return 0;
    else if( *s1 > *s2 ) return 1;
}
int main() {
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString), CompareString);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}
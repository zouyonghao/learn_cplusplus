#include <iostream>
using namespace std;
// 在此处补充你的代码
class CType {
  public:
    int n;
    void setvalue(int _n) { n = _n; }
    int operator++(int) {
        int old = n;
        n = n * n;
        return old;
    }
};
ostream & operator<<(ostream & o, CType & obj) {
    o << obj.n;
    return o;
}
int main(int argc, char *argv[]) {
    CType obj;
    int n;
    cin >> n;
    while (n) {
        obj.setvalue(n);
        cout << obj++ << " " << obj << endl;
        cin >> n;
    }
    return 0;
}
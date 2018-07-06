#include <iostream>
#include <list>
#include <string>
using namespace std;

class A {
  private:
    string name;

  public:
    A(string n) : name(n) {}
    friend bool operator<(const class A &a1, const class A &a2);
    friend bool operator==(const class A &a1, const class A &a2) {
        if (a1.name.size() == a2.name.size())
            return true;
        else
            return false;
    }
    friend ostream & operator<<(ostream &o, const A &a) {
        o << a.name;
        return o;
    }
    string get_name() const { return name; }
    int get_size() const { return name.size(); }
};
// 在此处补充你的代码
bool operator<(const class A &a1, const class A &a2) {
    return a1.get_size() < a2.get_size();
}
template <class T> class MyLarge {
  public:
    bool operator()(T a1, T a2) {
        return a1.get_name().c_str()[0] < a2.get_name().c_str()[0];
    }
};
// template <class T1 = A>
class Print {
  public:
    void operator()(const A &a) {
        cout << a << " ";
    }
};
template <class It, class Op>
void Show(It i, It e, Op o) {
    while (i != e) {
        o(*i);
        i++;
    }
}
int main(int argc, char *argv[]) {
    list<A> lst;
    int ncase, n, i = 1;
    string s;
    cin >> ncase;
    while (ncase--) {
        cout << "Case: " << i++ << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            lst.push_back(A(s));
        }
        lst.sort();
        Show(lst.begin(), lst.end(), Print());

        cout << endl;
        lst.sort(MyLarge<A>());
        Show(lst.begin(), lst.end(), Print());
        cout << endl;
        lst.clear();
    }
    return 0;
}
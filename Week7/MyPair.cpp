#include <iostream>
using namespace std;

template <class T1, class T2> class Pair {
  public:
    T1 key;
    T2 value;
    Pair(T1 _k, T2 _v) : key(_k), value(_v) {}
    bool operator<(const Pair<T1, T2> &p) const { return key < p.key; }
};

int main() {
    Pair<string, int> student("tom", 19);
    cout << student.key << " " << student.value << endl;
    return 0;
}
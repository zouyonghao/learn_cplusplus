#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    set<int> oldms;
    int n;
    cin >> n;
    while (n-- > 0) {
        string op;
        cin >> op;
        if (op == "add") {
            int x;
            cin >> x;
            ms.insert(x);
            oldms.insert(x);
            cout << ms.count(x) << endl;
        } else if (op == "del") {
            int x;
            cin >> x;
            cout << ms.count(x) << endl;
            pair<multiset<int>::iterator, multiset<int>::iterator> range =
                ms.equal_range(x);
            ms.erase(range.first, range.second);
        } else if (op == "ask") {
            int x;
            cin >> x;
            if (oldms.count(x) > 0) {
                cout << 1;
            } else {
                cout << 0;
            }
            cout << " " << ms.count(x) << endl;
        }
    }
    return 0;
}
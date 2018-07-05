#include <iostream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

int main() {

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    map<int, list<int> > m;
    while (n-- > 0) {
        string op;
        cin >> op;
        if (op == "new") {
            int id;
            list<int> l;
            cin >> id;
            pair<int, list<int> > p;
            p.first = id;
            p.second = l;
            m.insert(p);
        } else if (op == "add") {
            int id, num;
            cin >> id >> num;
            m.at(id).push_back(num);
        } else if (op == "merge") {
            int id1, id2;
            cin >> id1 >> id2;
            list<int> list1 = m.at(id1);
            list<int> list2 = m.at(id2);
            list1.merge(list2);
        } else if (op == "unique") {
            int id;
            cin >> id;
            m.at(id).sort();
            m.at(id).unique();//删除区间中连续相等的元素
        } else if (op == "out") {
            int id;
            cin >> id;
            list<int> l = m.at(id);
            l.sort();
            for (list<int>::const_iterator i = l.begin(); i != l.end(); i++) {
                cout << *i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
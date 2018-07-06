#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
// #include <stdio.h>

using namespace std;

int main() {

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    // scanf("%d", &n);
    ios::sync_with_stdio(false);
    cin >> n;
    map<int, int> member;
    member.insert(make_pair(1000000000, 1));
    while (n--) {
        int id, f;
        cin >> id >> f;
        // scanf("%d", &id);
        // scanf("%d", &f);
        map<int, int>::iterator p = member.lower_bound(f);
        int tmpId;
        if (p != member.begin()) {
            int leftf = (*(--p)).first;
            int leftid = (*p).second;
            int rightf = (*(++p)).first;
            int rightid = (*p).second;
            if (f - leftf <= rightf - f) {
                tmpId = leftid;
            } else {
                tmpId = rightid;
            }
        } else {
            tmpId = (*p).second;
        }
        cout << id << " " << tmpId << endl;
        // printf("%d %d\n", id, tmpId);
        member.insert(make_pair(f, id));
    }

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<double> q;
    q.push(1.1);
    q.push(2.1);
    q.push(9.8);
    while (!q.empty()) {
        cout << q.top() << ",";
        q.pop();
    }
    cout << endl;
    return 0;
}
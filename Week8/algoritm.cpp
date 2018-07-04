#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int array[] = {10, 20, 30, 40};
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int>::const_iterator p;
    p = find(v.begin(), v.end(), 3);
    if (p != v.end())
        cout << * p << endl;
    p = find(v.begin(), v.end(), 0);
    if (p == v.end())
        cout << "not found" << endl;
    p = find(v.begin() + 1, v.end() - 2, 2);
    if (p != v.end())
        cout << * p << endl;
    int * a = find(array, array + 4, 20);
    cout << * a << endl;
}
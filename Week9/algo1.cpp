#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <list>

using namespace std;

class CLessThan9 {
public:
    bool operator()(int n) {
        return n < 9;
    }
};

void outputSquare(int n) {
    cout << n * n << " ";
}

int calculateCube(int n) {
    return n * n * n;
}

int main() {
    const int SIZE = 10;
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[] = {100, 2, 8, 1, 50, 3, 8, 9, 10, 2};
    vector<int> v(a1, a1 + SIZE);
    ostream_iterator<int> output(cout, " ");
    random_shuffle(v.begin(), v.end());
    cout << endl << "1)";
    copy(v.begin(), v.end(), output);
    cout << endl << "a2:";
    copy(a2, a2 + SIZE, output);
    copy(a2, a2 + SIZE, v.begin());
    cout << endl << "2)";
    cout << count(v.begin(), v.end(), 8);
    cout << endl << "3)";
    cout << count_if(v.begin(), v.end(), CLessThan9());

    cout << endl << "4)";
    cout << * min_element(v.begin(), v.end());
    cout << endl << "5)";
    cout << * max_element(v.begin(), v.end());
    cout << endl << "6)";
    cout << accumulate(v.begin(), v.end(), 0);
    
    cout << endl << "7)";
    for_each(v.begin(), v.end(), outputSquare);

    cout << endl << "8)";
    vector<int> t(SIZE);
    transform(v.begin(), v.end(), t.begin(), calculateCube);
    copy(t.begin(), t.end(), output);

    return 0;
}
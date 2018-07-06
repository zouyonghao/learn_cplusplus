#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int n, i, j;
        cin >> n >> i >> j;
        // 第 i ~ j 位置1
        int k = ((1 << j) - 1) ^ ((1 << (i + 1)) - 1);
        // 第 i 位
        int ni = (((n >> i) & 1) << i);
        k = ni | k;
        // 第 j 位
        int nj = (((n >> j) & 1 ^ 1) << j);
        k = nj | k;
        printf("%x\n", k);
    }
    return 0;
}
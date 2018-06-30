// #include <iostream>
// #include <cstring>
// using namespace std;
// 在此处补充你的代码
class Array2 {
private:
    int row, column;
    int * ptr;
public:
    Array2(int r = 0, int c = 0):row(r), column(c) {
        if (0 == r || c ==0) {
            ptr = NULL;
        } else {
            ptr = new int[r * c];
        }
    }
    ~Array2() {
        if (ptr) delete [] ptr;
    }
    int * operator[](int i) {
        return (int *)(ptr +  i * column);;
    }
    int operator()(int i, int j) {
        return ptr[i * column + j];
    }
    Array2 & operator=(const Array2 & a) {
        if (a.ptr) {
            if (ptr) delete [] ptr;
            ptr = new int[a.row * a.column];
            memcpy(ptr, a.ptr, sizeof(int) * a.row * a.column);
        }
        row = a.row;
        column = a.column;
        return * this;
    }
};
// int main() {
//     Array2 a(3,4);
//     int i,j;
//     for(  i = 0;i < 3; ++i )
//         for(  j = 0; j < 4; j ++ )
//             a[i][j] = i * 4 + j;
//     for(  i = 0;i < 3; ++i ) {
//         for(  j = 0; j < 4; j ++ ) {
//             cout << a(i,j) << ",";
//         }
//         cout << endl;
//     }
//     cout << "next" << endl;
//     Array2 b;     b = a;
//     for(  i = 0;i < 3; ++i ) {
//         for(  j = 0; j < 4; j ++ ) {
//             cout << b[i][j] << ",";
//         }
//         cout << endl;
//     }
//     return 0;
// }
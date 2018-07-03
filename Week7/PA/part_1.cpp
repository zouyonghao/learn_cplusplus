// #include <iostream>
// using namespace std;
// 在此处补充你的代码
template <class T>
class CArray3D {
private:
    T *** array;
public:
    CArray3D(int a, int b, int c) {
        array = new T**[a];
        for (int i = 0; i < a; i++) {
            array[i] = new T*[b];
            for (int j = 0; j < c; j++) {
                array[i][j] = new T[c];
            }
        }
    }
    T** operator[](int a) {
        return array[a];
    }
};
// int main()
// {
//     CArray3D<int> a(3,4,5);
//     int No = 0;
//     for( int i = 0; i < 3; ++ i )
//         for( int j = 0; j < 4; ++j )
//             for( int k = 0; k < 5; ++k )
//                 a[i][j][k] = No ++;
//     for( int i = 0; i < 3; ++ i )
//         for( int j = 0; j < 4; ++j )
//             for( int k = 0; k < 5; ++k )
//                 cout << a[i][j][k] << ",";
//     return 0;
// }
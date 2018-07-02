#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout("a.dat", ios::out);
    ifstream fin("a.dat", ios::in);
    int x = 10;
    fout.seekp(0, ios::beg);
    fout.write((const char *)(&x), sizeof(int));
    fout.close();
    int y;
    fin.seekg(0, ios::beg);
    fin.read((char *)(&y), sizeof(int));
    fin.close();
    cout << y << endl;
    return 0;
}
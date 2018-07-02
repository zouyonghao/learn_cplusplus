#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Missing files" << endl;
        return 0;
    }
    ifstream inFile(argv[1], ios::in);
    if (!inFile) {
        cout << "Src file open error!" << endl;
        return 0;
    }
    ofstream outFile(argv[2], ios::out);
    if (!outFile) {
        cout << "Dest file open error!" << endl;
    }

    char c;
    while (inFile.get(c)) {
        outFile.write(&c, sizeof(c));
    }
    inFile.close();
    outFile.close();
    return 0;
}
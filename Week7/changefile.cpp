#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

class CStudent {
  public:
    char szName[20];
    int nScore;
};

int main() {
    CStudent s;
    fstream ioFile("students.dat", ios::in | ios::out | ios::binary);
    if (!ioFile) {
        cout << "file open error" << endl;
        return 0;
    }
    ioFile.seekp(sizeof(s) * 2, ios::beg);
    ioFile.write("BBB", strlen("BBB") + 1);
    ioFile.seekg(0, ios::beg);
    while(ioFile.read((char *) &s, sizeof(s))) {
        cout << s.szName << " " << s.nScore << endl;
    }
    return 0;
}
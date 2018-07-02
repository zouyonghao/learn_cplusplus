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
    ofstream ofile("students.dat", ios::out | ios::binary);
    while(cin >> s.szName >> s.nScore) {
        if (strcmp(s.szName, "exit") == 0) {
            break;
        }
        ofile.write((char *)&s, sizeof(s));
    }
    ofile.close();
    return 0;
}
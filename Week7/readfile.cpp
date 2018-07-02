#include <fstream>
#include <iostream>
using namespace std;
class CStudent {
  public:
    char szName[20];
    int nScore;
};

int main() {
    ifstream inFile("students.dat", ios::in | ios::binary);
    CStudent s;
    while(inFile.read((char *) &s, sizeof(s))) {
        cout << inFile.gcount() << endl;
        cout << s.szName << s.nScore << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

string str[21];
string number = "0123456789";

int getNumber(string);
string getString(string);

int find() {
    string S;
    cin >> S;
    S = getString(S);
    string Nstr;
    cin >> Nstr;
    int N = getNumber(Nstr);
    int pos = str[N].find(S);
    if (pos != string::npos) {
        return pos;
    } else {
        return S.size();
    }
}

int rfind() {
    string S;
    cin >> S;
    S = getString(S);
    string Nstr;
    cin >> Nstr;
    int N = getNumber(Nstr);
    int pos = str[N].rfind(S);
    if (pos != string::npos) {
        return pos;
    } else {
        return S.size();
    }
}

int getNumber(string Nstr) {
    if (Nstr == "find") {
        return find();
    } else if (Nstr == "rfind") {
        return rfind();
    } else {
        return atoi(Nstr.c_str());
    }
}

string copy() {
    string Nstr, Xstr, Lstr;
    cin >> Nstr;
    int N = getNumber(Nstr);
    cin >> Xstr;
    int X = getNumber(Xstr);
    cin >> Lstr;
    int L = getNumber(Lstr);
    return str[N].substr(X, L);
}
string add();

string getString(string S) {
    if (S == "add") {
        return add();
    } else if (S == "copy") {
        return copy();
    } else {
        return S;
    }
}

string add() {
    string S1;
    cin >> S1;
    S1 = getString(S1);
    string S2;
    cin >> S2;
    S2 = getString(S2);
    if (S1.find_first_not_of(number) == string::npos &&
        S2.find_first_not_of(number) == string::npos && atoi(S1.c_str()) >= 0 &&
        atoi(S1.c_str()) <= 99999 && atoi(S2.c_str()) >= 0 &&
        atoi(S2.c_str()) <= 99999) {
        return to_string(atoi(S1.c_str()) + atoi(S2.c_str()));
    } else {
        return S1 + S2;
    }
}

void insert() {
    string S;
    cin >> S;
    S = getString(S);
    string Nstr;
    cin >> Nstr;
    int N = getNumber(Nstr);
    string Xstr;
    cin >> Xstr;
    int X = getNumber(Xstr);
    str[N].insert(X, S);
}

void reset() {
    string S;
    cin >> S;
    S = getString(S);
    string Nstr;
    cin >> Nstr;
    int N = getNumber(Nstr);
    str[N] = S;
}

void print() {
    string Nstr;
    cin >> Nstr;
    int N = getNumber(Nstr);
    cout << str[N] << endl;
}

void printall(int n) {
    for (int i = 1; i <= n; i++) {
        cout << str[i] << endl;
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str[i];
    }
    string op;
    cin >> op;
    // freopen("test.txt", "w", stdout);
    while (op != "over") {
        if (op == "insert") {
            insert();
        } else if (op == "copy") {
            copy();
        } else if (op == "reset") {
            reset();
        } else if (op == "print") {
            print();
        } else if (op == "printall") {
            printall(n);
        }
        cin >> op;
    }
    return 0;
}

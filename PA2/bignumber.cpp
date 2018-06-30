#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class BigNumber {
private:
    string number;
public:
    BigNumber(string s):number(s) { }
    string operator+(BigNumber & b) {
        return add(number, b.number);
    }

    string add(string a, string b) {
        string c;
        string & longger = b.length() > a.length() ?
                         b : a;
        string & shortter = longger.c_str() == b.c_str() ? a : b;
        // cout << longger << "+" << shortter << endl;
        int i = longger.length() - 1;
        int p = 0;
        for (int j = shortter.length() - 1; i >= 0; i--, j--) {
            int n1 = longger.c_str()[i] - '0';
            int n2 = 0;
            if (j >= 0) {
                n2 = shortter.c_str()[j] - '0';
            }
            int result = n1 + n2 + p;
            c.insert(0, to_string(result % 10));
            p = result / 10;
        }
        if (p != 0) {
            c.insert(0, to_string(p));
        }
        return c;
    }

    string operator-(BigNumber & b) {
        string c;
        int compareResult = compare(number, b.number);
        switch(compareResult) {
            case 1:
                c = sub(number, b.number);
                break;
            case 0:
                c = "0";
                break;
            case -1:
                c = sub(b.number, number);
                c.insert(0, "-");
                break;
        }
        return c;
    }

    string sub(string bigger, string smaller) {
        if (bigger == smaller) {
            return "0";
        }
        string c;
        bool p = false; // 借位
        for (int i = bigger.length() - 1, j = smaller.length() - 1; i >= 0; i--, j--) {
            int n1 = bigger[i] - '0';
            int n2 = 0;
            if (j >= 0) {
                n2 = smaller[j] - '0';
            }
            int result;
            if (p) {
                n1 -= 1;
            }
            if (n1 >= n2) {
                result = n1 - n2;
                p = false;
            } else {
                result = n1 + 10 - n2;
                p = true;
            }
            if (result == 0 && i == 0) {
                break;
            }
            c.insert(0, to_string(result));
        }
        return c;
    }

    // a > b, 1
    // a = b, 0
    // a < b, -1
    int compare(string a, string b) {
        if (a.length() > b.length()) {
            return 1;
        } else if (a.length() == b.length()) {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] > b[i]) {
                    return 1;
                } else if (a[i] < b[i]) {
                    return -1;
                }
            }
            return 0;
        } else {
            return -1;
        }
    }

    string operator*(const BigNumber & b) {
        string c;
        int compareResult = compare(number, b.number);
        switch(compareResult) {
            case 1:
            case 0:
                c = mul(number, b.number);
                break;
            case -1:
                c = mul(b.number, number);
                break;
        }
        return c;
    }

    string mul(string bigger, string smaller) {
        string c;
        for (int i = smaller.length() - 1; i >= 0; i--) {
            int p = 0; // 进位
            int result = 0;
            string tmp;
            for (int j = bigger.length() - 1; j >= 0; j--) {
                result = (bigger[j] - '0') * (smaller[i] - '0') + p;
                p = result / 10;
                result = result % 10;
                tmp.insert(0, to_string(result));
            }
            for (int j = 0; j < smaller.length() - 1 - i; j++) {
                tmp.push_back('0');
            }
            if (p != 0) {
                tmp.insert(0, to_string(p));
            }
            c = add(c, tmp);
        }
        // trim 0
        for (int i = 0; i < c.length() - 1; i++) {
            if (c[i] == '0') {
                c = c.substr(i + 1);
            } else {
                break;
            }
        }
        return c;
    }

    string operator/(const BigNumber & b) {
        int compareResult = compare(number, b.number);
        switch(compareResult) {
            case 0:
                return "1";
            case -1:
                return "0";
        }
        return div(number, b.number);
    }

    string div(string bigger, string smaller) {
        string c;
        string r = "0"; // 余数
        int pos = 0;
        for (int i = smaller.length() - 1; i < bigger.length(); i++) {
            string currentStr = bigger.substr(pos, i - pos + 1);
            int n = 0; // 商
            r = mul(r, "10");
            r = add(r, currentStr);
            // r >= smaller
            while (compare(r, smaller) != -1) {
                r = sub(r, smaller);
                n++;
            }
            if (compare(r, "0") == -1) {
                r += smaller;
                n--;
            }
            if (c.empty() && n == 0) {
                continue;
            }
            c.append(to_string(n));
            pos = i + 1;
        }
        return c;
    }
};

int main() {
    string a1;
    char op;
    string a2;
    cin >> a1 >> op >> a2;
    BigNumber b1(a1);
    BigNumber b2(a2);
    switch(op) {
        case '+':
            cout << (b1 + b2);
            break;
        case '-':
            cout << (b1 - b2);
            break;
        case '*':
            cout << (b1 * b2);
            break;
        case '/':
            cout << (b1 / b2);
            break;
    }
    return 0;
}
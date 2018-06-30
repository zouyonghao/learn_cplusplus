#include <iostream>
#include <string>
using namespace std;
class CStudent {
private:
    string name;
    string id;
    int age;
    char gender;
public:
    void PrintInfo();
    void SetInfo(const string & name_, const string & id_,
                 int age_, char gender_);
};
class CUndergraduateStudent:public CStudent {
private:
    string department;
public:
    void PrintInfo() {
        CStudent::PrintInfo();
        cout << "Department:" << department << endl;
    }
    void SetInfo(const string & name_, const string & id_,
                 int age_, char gender_, const string & department_) {
        CStudent::SetInfo(name_, id_, age_, gender_);
        this->department = department_;
    }
};
void CStudent::PrintInfo() {
    cout << "Name:" << name << endl;
    cout << "ID:" << id << endl;
    cout << "Age:" << age << endl;
    cout << "Gender:" << gender << endl;
}
void CStudent::SetInfo(const string & name_, const string & id_,
                       int age_, char gender_) {
    name = name_;
    id = id_;
    age = age_;
    gender = gender_;
}

int main() {
    CUndergraduateStudent h;
    h.SetInfo("Harry Potter", "123", 19, 'M', "Computer Science");
    h.PrintInfo();
    return 0;
}
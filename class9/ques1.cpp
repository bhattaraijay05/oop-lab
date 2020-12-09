// 1. Write a suitable program for the following
// class Employee{/.../};
// class Manager public Employee{/...]}; class Director:public Manager{/...]};
// class Temporary\...]);
// class Secretary public Employee{/.../); class Tsec:public Temporary,public Secretary[/* */);
// class Consultant public Temporary public Manager{/.../);
#include <iostream>

using namespace std;

class Employee
{
public:
    int empNo;
    string empName;
    Employee(string name, int no) : empName(name), empNo(no) {}
};

class Manager : public Employee
{
public:
    int manSal;
    Manager(string name, int no, int Sal) : Employee(name, no), manSal(Sal) {}
    void manDisp()
    {
        cout << "\n Manager      : " << empName;
        cout << "\n Employee No. : " << empNo << "\n Manager Salary : " << manSal;
        cout << "\n--------------------------------------------------";
    }
};

class Director : public Manager
{
public:
    string empDept;
    Director(string name, int no, int Sal, string dept) : Manager(name, no, Sal), empDept(dept) {}
    void dirDisp()
    {
        cout << "\n Director     : " << empName << "\n Department   : " << empDept;
        cout << "\n Employee No. : " << empNo << "\n Director Salary : " << manSal;
        cout << "\n----------------------------------------------------";
    }
};

class Temporary
{
public:
    string tempEmpName;
    int tempEmpNo;
    Temporary() : tempEmpName("NULL"), tempEmpNo(0) {}
};

class Secretary : public Employee
{
public:
    int secSal;
    Secretary(string name, int no, int Sal) : Employee(name, no), secSal(Sal) {}
    void secDisp()
    {
        cout << "\n Secretery    : " << empName;
        cout << "\n Employee No. : " << empNo << "\n  Secretery Salary : " << secSal;
        //cout << "\n--------------------------------------------------";
    }
};

class Tsec : public Temporary, public Secretary
{
public:
    int tempSecSal;
    Tsec() : Temporary(), Secretary("NUll", 0, 0), tempSecSal(0) {}
    void TsecDisp();
};

void Tsec::TsecDisp()
{
    cout << "\n Existing Secretary ->";
    secDisp();
    cout << "\n\n New Temporary Secretary ->";
    cout << "\n Temporary Secretary Name   : " << tempEmpName;
    cout << "\n Temporary Secretary No.    : " << tempEmpNo;
    cout << "\n Temporary Secretary Salary : " << tempSecSal;
    cout << "\n----------------------------------------------------";
}

class Consultant : public Temporary, public Manager
{
public:
    int tempConsSal;
    Consultant() : Temporary(), Manager("NUll", 0, 0), tempConsSal(0) {}
    void consDisp();
};

void Consultant::consDisp()
{
    cout << "\n Existing Manager ->";
    manDisp();
    cout << "New Temporary Consultant ->";
    cout << "\n Temporary Consultant Name   : " << tempEmpName;
    cout << "\n Temporary Consultant No.    : " << tempEmpNo;
    cout << "\n Temporary Consultant Salary : " << tempConsSal;
    cout << "\n----------------------------------------------------";
}

int main()
{
    cout << "\n Hello World !!!";
    Director D("shivagami Devi", 999, 20000, "Mahishmati");
    Manager M("Amarendra Bahubali", 989, 19000);
    Secretary S("Kattapa", 979, 15000);
    Tsec T;
    Consultant C;

    D.dirDisp();
    M.manDisp();
    S.secDisp();
    T.TsecDisp();
    C.consDisp();
    return 0;
}
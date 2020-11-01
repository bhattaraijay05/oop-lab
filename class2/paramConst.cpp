/* 3.Given that an EMPLOYEE class contains following members: Employee Number, Employee Name, Basic, DA, IT, Net Salary. Member functions: to read the data, to calculate Net Salary and to print data members.  Write a C++ program to read the data of N employees and compute Net Salary of each employee. (Dearness Allowance (DA) = 52% of Basic and Income Tax (IT) = 30% of the gross salary. Net Salary = Basic + DA - IT).
- prepare default constructor, parameterized constructor
- array of objects
- add  */
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Employee
{
private:
    string empName;
    int empNum;
    double empBI, empDA, empIT, empSal;

public:
    void read();
    void calcSal();
    void display();
    Employee();
    Employee(string, int, double);
};

void Employee ::read()
{
    cout << "Enter employee name and number : " << endl;
    cin >> empName >> empNum;
    cout << "Enter basic income : " << endl;
    cin >> empBI;
}

void Employee ::calcSal()
{
    empDA = (52 * empBI) / 100;
    double empGross = empBI + empDA;
    empIT = (30 * empGross) / 100;
    empSal = (empGross)-empIT;
}

void Employee ::display()
{
    cout << "\nEMPLOYEE DETAILS - \n";
    cout << "Name : " << empName << endl;
    cout << "Number : " << empNum << endl;
    cout << "Basic Income : " << empBI << endl;
    cout << "Dearness Allowance : " << empDA << endl;
    cout << "Income Tax : " << empIT << endl;
    cout << "Net Salary : " << empSal << endl;
}

Employee::Employee()
{
    empName = "NULL";
    empNum = 0;
    empBI = 0;
}
Employee::Employee(string ename, int eno, double bi)
{
    empName = ename;
    empNum = eno;
    empBI = bi;
}
int main()
{
    Employee e1;
    e1.read();
    e1.calcSal();
    e1.display();
    // cout << "\n\nDetails of first employee are : \n";
    // Employee e2("Default", 2, 25000);
    // e2.calcSal();
    // e2.display();
    return 0;
}
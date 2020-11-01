// Given that an EMPLOYEE class contains following members: Employee Number, Employee Name, Basic, DA, IT, Net Salary. Member functions: to read the data, to calculate Net Salary and to print data members.  Write a C++ program to read the data of numberOfEmployee employees and compute Net Salary of each employee. (Dearness Allowance (DA) = 52% of Basic and Income Tax (IT) = 30% of the gross salary. Net Salary = Basic + DA - IT).

#include <iostream>
#include <string.h>

using namespace std;

class Employee
{
private:
    char empName[10];
    int empNum;
    float Basic, DA, IT, netSal;

public:
    void readData();
    void calcSalary();
    void printData();
};

void Employee::readData()
{
    cout << "\n Employee Name : ";
    cin >> empName;
    cout << "\n Employee Number : ";
    cin >> empNum;
    cout << "\n Basic salary :";
    cin >> Basic;
}

void Employee::printData()
{
    cout << "\n Employee Name        : " << empName;
    cout << "\n Employee Number      : " << empNum;
    cout << "\n Basic salary         : " << Basic;
    cout << "\n Dearness Allowance   : " << DA;
    cout << "\n Income Tax           : " << IT;
    cout << "\n Net salary is        : " << netSal;
    cout << "\n -----------  \n\n";
}

void Employee::calcSalary()
{
    DA = Basic * 0.52;
    IT = (Basic + DA) * 0.3;
    netSal = Basic + DA - IT;
}

int main()
{
    int numberOfEmployee;
    cout << "\nEnter the number of employee:  ";
    cin >> numberOfEmployee;
    Employee E[10];
    for (int i = 0; i < numberOfEmployee; i++)
    {
        cout << "\n Data for employee " << i + 1;
        E[i].readData();
        E[i].calcSalary();
        E[i].printData();
    }
    for (int i = 0; i < numberOfEmployee; i++)
    {
        cout << "\n Data for employee " << i + 1;
        E[i].printData();
    }
}
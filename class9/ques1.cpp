// 1. Write a suitable program for the following
// class Employee{/*...*/};
// class Manager:public Employee{/*...*/};
// class Director:public Manager{/*...*/};
// class Temporary{/*...*/};
// class Secretary:public Employee{/*...*/};
// class Tsec:public Temporary,public Secretary{/*...*/};
// class Consultant:public Temporary,public Manager{/*...*/};

#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string firstName, lastName;
    void readData()
    {
        cin >> firstName >> lastName;
    }
    void displayData()
    {
        cout << "First Name:" << firstName << endl;
        cout << "Last Name:" << lastName << endl;
    }
};

class Manager : public Employee
{
public:
    void readManagerData()
    {
        cout << "Enter the First Name and Last Name of the Manager" << endl;
        Employee::readData();
    }
    void displayManagerData()
    {
        Employee::displayData();
    }
};

class Director : public Manager
{
};

class Temporary
{
};
class Secretary : public Employee
{
};
class Tsec : public Temporary, public Secretary
{
};
class Consultant : public Temporary, public Manager
{
};

int main()
{
    Manager m1;
    m1.readManagerData();
    m1.displayManagerData();
    return 0;
}
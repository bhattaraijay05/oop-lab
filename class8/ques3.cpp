// Consider a class Employee which has a derived class SalesPerson. Salesperson can further be distinguished into FullTimeSalesPerson and PartTimeSalesPerson. Assume suitable attributes and member functions to print variations in Bonus and workHrs (an attribute) for FullTimeSalesPerson and PartTimeSalesPerson.

#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string firstName, lastName;
    float salary, workHours;
    void readData();
    void displayData();
};

void Employee::readData()
{
    cout << "First Name: " << endl;
    cin >> firstName;
    cout << "Last Name: " << endl;
    cin >> lastName;
    cout << "Salary: " << endl;
    cin >> salary;
    cout << "Work Hours: " << endl;
    cin >> workHours;
}

void Employee::displayData()
{
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Salary: " << salary << endl;
    cout << "Work Hours: " << workHours << endl;
}

class SalesPerson : public Employee
{
};
class FullTimeSalesPerson : public SalesPerson
{
};

class PartTimeSalesPerson : public SalesPerson
{
};

int main()
{

    return 0;
}
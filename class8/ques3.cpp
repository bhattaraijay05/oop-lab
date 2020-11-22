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
public:
    float bonus;
    void readBonus()
    {
        cout << "Enter the bonus amount: " << endl;
        cin >> bonus;
    }
    void displayBonus()
    {
        cout << "Type of Employee: " << bonus << endl;
    }
};
class FullTimeSalesPerson : public SalesPerson
{
public:
    void readDetails()
    {
        cout << "\nEnter the details of Full time sales person" << endl;
        readData();
        readBonus();
    }
    void displayDetails()
    {
        cout << "\nDetails of full time sales person" << endl;
        displayData();
        displayBonus();
    }
};

class PartTimeSalesPerson : public SalesPerson
{
public:
    void readDetails()
    {
        cout << "\nEnter the details of Part time sales person" << endl;
        readData();
        readBonus();
    }
    void displayDetails()
    {
        cout << "\nDetails of part time sales person" << endl;
        displayData();
        displayBonus();
    }
};

int main()
{
    FullTimeSalesPerson f1;
    PartTimeSalesPerson p1;
    f1.readDetails();
    p1.readDetails();

    f1.displayDetails();
    p1.displayDetails();

    cout << "\nFull Time Sales Person works " << f1.workHours - p1.workHours << " more than Part Time Sales Person " << endl;
    cout << "\nFull Time Sales Person gets bonus of " << f1.bonus << " while part Time Sales Person gets bonus of " << p1.bonus << endl;

    return 0;
}
// For a class Person, derived classes are Faculty, NonTeaching and OfficeStaff. Assume suitable attributes and member functions to raise the functionalities.

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string firstName, lastName;
    Person() : firstName("NULL"), lastName("NULL") {}
    void ReadData();
    void DisplayData();
};

void Person::ReadData()
{
    cin >> firstName >> lastName;
}

void Person::DisplayData()
{
    cout << "First Name: " << firstName << endl
         << "Last Name: " << lastName << endl;
}

class Faculty : public Person
{
public:
    void readData()
    {
        cout << "Enter the first name and last name of the Faculty: " << endl;
        ReadData();
    }
    void displayData()
    {
        cout << "\nThe details of the Faculty: " << endl;
        DisplayData();
    }
};
class NonTeaching : public Person
{
public:
    void readData()
    {
        cout << "Enter the first name and last name of the Non Teaching Staff : " << endl;
        ReadData();
    }
    void displayData()
    {
        cout << "\nThe details of the NonTeaching Staff: " << endl;
        DisplayData();
    }
};
class OfficeStaff : public Person
{
public:
    void readData()
    {
        cout << "Enter the first name and last name of the Office Staff: " << endl;
        ReadData();
    }
    void displayData()
    {
        cout << "\nThe details of the Office Staff: " << endl;
        DisplayData();
    }
};

int main()
{

    Faculty f1;
    NonTeaching n1;
    OfficeStaff o1;
    f1.readData();
    n1.readData();
    o1.readData();
    f1.displayData();
    n1.displayData();
    o1.displayData();
    return 0;
}
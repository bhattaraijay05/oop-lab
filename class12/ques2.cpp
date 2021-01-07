//  Implement the following relationship using appropriate member variables and
// member functions

//                  Person
//                 Name AGE
//                /         \
//               /           \
//              /             \
//         Student          Faculty
//              \             /
//               \           /
//                 \       /
//                     TA

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;
    void enterDetails();
    void displayDetails();
};

void Person::enterDetails()
{
    cout << "Name: " << endl;
    cin >> name;
    cout << "Age: " << endl;
    cin >> age;
}

void Person::displayDetails()
{
    cout << "Name: " << name << endl
         << "Age:" << age << endl;
}

class Student : public Person
{
public:
    string usn;
    void enterDetails()
    {
        Person::enterDetails();
        cout << "USN: " << endl;
        cin >> usn;
    }
    void displayDetails()
    {
        cout << "\nDetails of Student" << endl;
        Person::displayDetails();
        cout << "USN: " << usn << endl;
    }
};

class Faculty : public Person
{
public:
    string subject;
    void enterDetails()
    {
        Person::enterDetails();
        cout << "Enter your subject: " << endl;
        cin >> subject;
    }
    void displayDetails()
    {
        cout << "\nDetails of Faculty" << endl;
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Ta : public Student, public Faculty
{
public:
    void enterDetails()
    {
        Student::enterDetails();
        cout << "Enter your subject: " << endl;
        cin >> Faculty::subject;
    }
    void displayDetails()
    {
        cout << "Details of TA" << endl;
        Student::displayDetails();
        cout << Faculty::subject << endl;
    }
};

int main()
{
    Ta t;
    Student s;
    Faculty f;
    cout << "Enter details for student " << endl;
    s.enterDetails();
    s.displayDetails();
    cout << "Enter details for faculty " << endl;
    f.enterDetails();
    f.displayDetails();
    cout << "Enter details for TA " << endl;
    t.enterDetails();
    t.displayDetails();

    return 0;
}
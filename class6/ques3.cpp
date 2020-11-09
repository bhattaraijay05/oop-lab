//  Prepare a class Student with suitable attributes and member functions. Add a friend function Predict to print the grade for a course.
#include <iostream>
#include <string>
using namespace std;

class Student
{
    string studentName;
    int rollNo, marks;

public:
    void enterData();
    void DisplayData();
    friend Student studentData(Student);
};

void Student::enterData()
{
    cout << "Enter the name, roll number and marks of the student: ";
    cin >> studentName >> rollNo >> marks;
}

void Student::DisplayData()
{
    cout << "Student details: " << endl;
    cout << "Name : " << studentName << endl
         << "Roll Number : " << rollNo << endl
         << "Marks : " << marks << endl;
}
Student studentData(Student s1)
{
    Student stu;
    stu.marks = s1.marks;
    cout << "The grade of student is: ";
    if (stu.marks > 100 || stu.marks < 0)
    {
        cout << "Enter valid marks ";
    }
    else if (stu.marks > 90 && stu.marks < 100)
    {
        cout << "S";
    }
    else if (stu.marks > 80 && stu.marks < 90)
    {
        cout << "A";
    }
    else if (stu.marks > 70 && stu.marks < 80)
    {
        cout << "B";
    }
    else if (stu.marks > 60 && stu.marks < 70)
    {
        cout << "C";
    }
    else if (stu.marks > 50 && stu.marks < 60)
    {
        cout << "D";
    }
    else if (stu.marks > 40 && stu.marks < 50)
    {
        cout << "E";
    }
    else
    {
        cout << "F";
    }
    return stu;
}
int main()
{
    Student student1, stu;
    student1.enterData();
    student1.DisplayData();
    stu = studentData(student1);
    return 0;
}
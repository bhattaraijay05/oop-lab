//  Prepare a class Student with suitable attributes and member functions. Add a friend function Predict to print the grade for a course.
#include <iostream>
using namespace std;

class Student
{
    string studentName;
    int rollNo, marks[5];

public:
    void enterData();
    void DisplayData();
    friend Student studentData(Student);
};
int main()
{

    return 0;
}
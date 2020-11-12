// Consider a class Student with marks. Compare marks of two students using comparison operators.

#include <iostream>
using namespace std;

class Student
{
    int marks;

public:
    Student()
    {
        marks = 0;
    }
    Student(int m)
    {
        marks = m;
    }

    void readData();
    friend bool operator>(Student s1, Student s2);
    friend bool operator==(Student s1, Student s2);
};
void Student::readData()
{
    cout << "Enter the marks of student: ";
    cin >> marks;
}

bool operator>(Student s1, Student s2)
{
    return s1.marks > s2.marks;
}
bool operator==(Student s1, Student s2)
{
    return s1.marks == s2.marks;
}
int main()
{
    Student s1, s2;
    s1.readData();
    s2.readData();
    if (s1 > s2)
        cout << "Student 1 got higher marks. " << endl;
    else if (s1 == s2)

        cout << "Both got the same mark. " << endl;

    else
        cout << "Student 2 got higher marks. " << endl;

    return 0;
}
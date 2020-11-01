// Write a C++ program to create array of object of class student with data members for storing his USN, marks of six subjects for three tests and member functions to input display and calculate the avg marks for each subject taking best two of three subjects. Write a tester program to test these classes.

#include <iostream>
using namespace std;

class Students
{
private:
    char studentUsn[10];
    int marks[6][3];

public:
    void inputData();
    void displayData();
    void calculateData();
};

void Students ::inputData()
{
    cout << "\nEnter the USN of the student: ";
    cin >> studentUsn;
    int numberOfStudents = 10;

    for (int i = 1; i < numberOfStudents; i++)
    {
    }
};

int main()
{

    return 0;
}
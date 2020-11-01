// 5.Program to depict command line arguments to compute fabonicci number of nth term.
#include <iostream>
using namespace std;

int main()
{
    int firstTerm, nextTerm = 0, tempTerm = 1, numberOfElements;

    cout << "Enter a positive number: ";
    cin >> numberOfElements;

    cout << "Fibonacci Series: " << firstTerm << ", " << tempTerm << ", ";

    nextTerm = firstTerm + tempTerm;

    while (nextTerm <= numberOfElements)
    {
        cout << nextTerm << ", ";
        firstTerm = tempTerm;
        tempTerm = nextTerm;
        nextTerm = firstTerm + tempTerm;
    }
    return 0;
}
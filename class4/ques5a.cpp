// 5.Program to depict command line arguments to compute fabonicci number of nth term.
#include <iostream>
using namespace std;

int main()
{
    int n, firstTerm = 0, tempTerm = 1, nextTerm = 0;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            cout << " " << firstTerm;
            continue;
        }
        if (i == 2)
        {
            cout << tempTerm << " ";
            continue;
        }
        nextTerm = firstTerm + tempTerm;
        firstTerm = tempTerm;
        tempTerm = nextTerm;
        cout << nextTerm << " ";
    }
    return 0;
}
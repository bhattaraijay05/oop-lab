#include <iostream>
using namespace std;
class STUDENT
{
private:
    int usn;
    char name[20];
    float marks[3], avg;

public:
    STUDENT();
    ~STUDENT();
    void getdata();
    void putdata();
    void calavg();
};

//CONSTRUCTOR
STUDENT ::STUDENT() {}
//DESTRUCTOR

STUDENT ::~STUDENT() {} //MEMBER FUNCTION TO INPUT DATA
void STUDENT ::getdata()
{
    cout << " USN : ";
    cin >> usn;
    cout << " NAME : ";
    cin >> name;
    for (int i = 0; i < 3; i++)
    {
        cout << endl
             << "Please enter marks in Test " << i + 1 << " : ";
        cin >> marks[i];
    }
} //MEMBER FUNCTION TO OUTPUT DATA
void STUDENT ::putdata() { cout << endl
                                << "Student USN : " << usn << endl
                                << "Student NAME : " << name << endl
                                << "Average Marks : " << avg; } //MEMBER FUNCTION TO CALCULATE AVERAGE
void STUDENT ::calavg()
{
    if (marks[0] < marks[1] && marks[0] < marks[2])
        avg = (marks[1] + marks[2]) / 2.0;
    else if (marks[1] < marks[0] && marks[1] < marks[2])
        avg = (marks[0] + marks[2]) / 2.0;
    else
        avg = (marks[1] + marks[0]) / 2.0;
}
int main()
{
    STUDENT s[10];
    int i, n;
    cout << endl
         << "Enter number of students N : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << endl
             << "Enter " << i + 1 << " Student's data : " << endl;
        s[i].getdata();
        s[i].calavg();
    }
    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << endl
             << " Details of student (" << i + 1 << ")" << endl;
        cout << " ======================" << endl;
        s[i].putdata();
    }
    return 0;
}
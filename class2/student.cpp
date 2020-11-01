#include <iostream>
#define N 6
using namespace std;

struct sub
{
    int t1, t2, t3;
    float avg;
};

sub subavg(sub subject)
{
    if (subject.t1 >= subject.t2 && subject.t1 >= subject.t3)
    {
        if (subject.t2 >= subject.t3)
            subject.avg = (subject.t1 + subject.t2) / 2;
        else
            subject.avg = (subject.t1 + subject.t3) / 2;
    }
    if (subject.t2 >= subject.t1 && subject.t2 >= subject.t3)
    {
        if (subject.t1 >= subject.t3)
            subject.avg = (subject.t1 + subject.t2) / 2;
        else
            subject.avg = (subject.t2 + subject.t3) / 2;
    }
    if (subject.t3 >= subject.t2 && subject.t3 >= subject.t1)
    {
        if (subject.t2 >= subject.t1)
            subject.avg = (subject.t3 + subject.t2) / 2;
        else
            subject.avg = (subject.t1 + subject.t3) / 2;
    }
    return subject;
}

class student
{
private:
    int stud_usn;
    sub sMarks[N];

public:
    void readData();
    void printData();
    void calAvg();
};

void student::readData()
{
    cout << "\n Enter USN: ";
    cin >> stud_usn;
    cout << "\n Enter marks for 6 subjects in each test ->";
    cout << "\n Test 1->\n";
    for (int i = 0; i < N; i++)
    {
        cout << " Subject " << i + 1 << ": ";
        cin >> sMarks[i].t1;
    }
    cout << "\n Test 2->\n";
    for (int i = 0; i < N; i++)
    {
        cout << " Subject " << i + 1 << ": ";
        cin >> sMarks[i].t2;
    }
    cout << "\n Test 3->\n";
    for (int i = 0; i < N; i++)
    {
        cout << " Subject " << i + 1 << ": ";
        cin >> sMarks[i].t3;
    }
}

void student::calAvg()
{
    for (int i = 0; i < N; i++)
    {
        sMarks[i] = subavg(sMarks[i]);
    }
}

void student::printData()
{
    cout << "\n USN : " << stud_usn;
    for (int i = 0; i < N; i++)
    {
        cout << "\n Marks in subject " << i + 1;
        cout << "\n Test 1 : " << sMarks[i].t1;
        cout << "\n Test 2 : " << sMarks[i].t2;
        cout << "\n Test 3 : " << sMarks[i].t3;
        cout << "\n AVG    : " << sMarks[i].avg;
    }
}

int main()
{
    int n;
    cout << "\n Enter no. of students -> ";
    cin >> n;
    student stud[10];
    cout << "\n Enter student data ->";
    for (int i = 0; i < n; i++)
    {
        cout << "\n Student " << i + 1;
        stud[i].readData();
        stud[i].calAvg();
    }
    cout << "\n Collected data ->";
    for (int i = 0; i < n; i++)
    {
        cout << "\n Student " << i + 1;
        stud[i].printData();
    }
    return 0;
}
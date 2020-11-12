// Consider a class Date with year, month and day. Perform prefix and postfix increment operators for the Date suitably to show the new values.
#include <iostream>
using namespace std;
class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void readData();
    void displayData();
    friend Date operator++(Date );
    friend Date operator++(Date , int);
};

void Date::readData()
{
    cout << "Enter Day:";
    cin >> day;
    cout << "Enter Month:";
    cin >> month;
    cout << "Enter Year:";
    cin >> year;
}
void Date::displayData()
{
    cout << "Date:" << day << "-" << month << "-" << year << endl;
}

Date operator++(Date d1)
{
    ++d1.day;
    ++d1.month;
    ++d1.year;
    return d1;
}

Date operator++(Date d1, int)
{
    d1.day++;
    d1.month++;
    d1.year++;
    return d1;
}

int main()
{
    Date date1, date2, date3;
    date1.readData();
    date1.displayData();
    date3 = (date1)++;
    date3.displayData();
    date2 = ++(date1);
    date2.displayData();

    return 0;
}
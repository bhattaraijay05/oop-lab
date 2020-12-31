// 1. Imagine a publishing company that markets both book and audio cassette versions of its work. Create a class publication that stores the title and price of a publication and member functions getdata() and displaydata(). From this class derive two classes: book which adds a page count and tape which adds a plain time in minutes. Write a main program to test the book and tape classes by creating instances of them

#include <iostream>
#include <string>
using namespace std;
class Publication
{
    string title;
    float price;

public:
    void getdata();
    void displaydata();
};
void Publication::getdata()
{

    cout << "Enter title of publication: ";
    cin >> title;
    cout << "Enter price of publication: ";
    cin >> price;
}
void Publication::displaydata()
{
    cout << "Publication title: " << title << endl;
    cout << "Publication price: " << price << endl;
}
class Book : public Publication
{
    int pagecount;

public:
    void getdata()
    {
        cout << "\nEnter the data for booK\n";
        Publication::getdata();
        cout << "Enter Book Page Count: ";
        cin >> pagecount;
    }
    void displaydata()
    {
        Publication::displaydata();
        cout << "Book page count: " << pagecount << endl;
    }
};
class Tape : public Publication
{
    float ptime;

public:
    void getdata()
    {
        cout << "\nEnter the data for Tape\n";
        Publication::getdata();
        cout << "Enter tap's playing time in minutes: ";
        cin >> ptime;
    }
    void displaydata()
    {
        Publication::displaydata();
        cout << "Tap's playing time is " << ptime << " minutes." << endl;
    }
};
int main(void)
{
    Book B1;
    Tape T1;
    B1.getdata();
    T1.getdata();
    B1.displaydata();
    T1.displaydata();
}
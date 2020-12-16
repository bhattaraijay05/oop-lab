#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
    string firstName, lastName, answer;
    int marks = 20;

public:
    void readStudentDetails();
    void getQuestions(string);         //Function Overloading
    void getQuestions(string, string); //Function Overloading
    void displayMark();
    void saveResult();
    Student operator++(int);
};

class QuizStudent : public Student //Inheritance
{
public:
    void getQuestions(string ques, string opt) //Function Overriding
    {
        cout << "Your Questions" << endl;
        Student::getQuestions(ques, opt);
    }
};

class FillInTheBlanksStudent : public Student //Inheritance
{
public:
    void getQuestions(string ques) //Function Overriding
    {
        cout << "\nYour Questions" << endl;
        Student::getQuestions(ques);
    }
};
void Student::readStudentDetails()
{
    cout << "\nEnter your details " << endl;
    cout << "\nFirst Name" << endl;
    cin >> firstName;
    cout << "\nLast Name" << endl;
    cin >> lastName;
}

void Student::saveResult()
{
    fstream file;
    file.open(firstName, fstream::out);
    file << "Name : " << firstName << " " << lastName << endl
         << "Marks : " << marks << endl;
    file.close();
}

void Student::displayMark()
{
    cout << "\n...Result..." << endl;
    cout << "Name : " << firstName << " " << lastName << endl
         << "Marks : " << marks;
}

void Student::getQuestions(string quesFile)
{
    fstream question;
    question.open(quesFile);

    string str;
    while (getline(question, str))
    {
        cout << str << "\n";
        cin >> answer;
        // if (answer == "10")
        // {
        //     cout << marks;
        // }
    }
}

void Student::getQuestions(string quesFile, string opFile)
{
    fstream question, option;
    question.open(quesFile);
    option.open(opFile);
    string ques, opts;
    while (getline(question, ques))
    {
        cout << ques << "\n";
        while (getline(option, opts))
        {

            cout << opts << "\n";
            cin >> answer;
            break;
        }
    }
}

int main()
{
    int testChoice;
    cout << "Enter your choice for the examination \n\n1: Quiz\n2: Fill In the blanks\n"
         << endl;
    cin >> testChoice;
    if (testChoice == 1)
    {
        QuizStudent Q1;
        Q1.readStudentDetails();
        Q1.getQuestions("questions.txt", "options.txt");
        Q1.displayMark();
        Q1.saveResult();
    }
    else if (testChoice == 2)
    {
        FillInTheBlanksStudent F1;
        F1.readStudentDetails();
        F1.getQuestions("fillBlanksQues.txt");
        F1.displayMark();
        F1.saveResult();
    }
}

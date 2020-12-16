#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
    string firstName, lastName, answer, usn;
    int marks = 0;

public:
    void readStudentDetails();
    void getQuestions(string);         //Function Overloading
    void getQuestions(string, string); //Function Overloading
    void displayMark();
    void saveResult();
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
    cout << "\nUSN" << endl;
    cin >> usn;
}

void Student::saveResult()
{
    fstream file;
    file.open(usn, fstream::out);
    file << "Name : " << firstName << " " << lastName << endl
         << "USN : " << usn << endl
         << "Marks : " << marks << endl;
    file.close();
}

void Student::displayMark()
{
    cout << "\n...Result..." << endl;
    cout << "Name : " << firstName << " " << lastName << endl
         << "USN : " << usn << endl
         << "Marks : " << marks;
}

void Student::getQuestions(string quesFile)
{
    fstream question, answerFile;
    question.open(quesFile);
    answerFile.open("fillBlanksAns.txt");
    string ans;
    while (getline(question, ans))
    {
        cout << ans << "\n";
        cin >> answer;
        while (getline(answerFile, ans))
        {
            if (ans == answer)
            {
                marks = marks + 1;
            }
            break;
        }
    }
}

void Student::getQuestions(string quesFile, string opFile)
{
    fstream question, option, answerFile;
    question.open(quesFile);
    answerFile.open("answers.txt");
    option.open(opFile);
    string ques, opts, ans;
    while (getline(question, ques))
    {
        cout << ques << "\n";
        while (getline(option, opts))
        {

            cout << opts << "\n";
            cin >> answer;
            while (getline(answerFile, ans))
            {
                if (ans == answer)
                {
                    marks = marks + 1;
                }
                break;
            }
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

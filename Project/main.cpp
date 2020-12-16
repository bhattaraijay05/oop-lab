#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
    string firstName, lastName, studentAnswer, usn;
    int marks = 0;

public:
    void readStudentDetails();
    void getQuestions(string);         //Function Overloading
    void getQuestions(string, string); //Function Overloading
    void displayResult();
    void saveResult();
    friend bool operator<(Student, Student);  //friend function and operator overloading
    friend bool operator==(Student, Student); //friend function and operator overloading
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

bool operator<(Student S1, Student S2)
{
    return S1.marks < S2.marks;
}

bool operator==(Student S1, Student S2)
{
    return S1.marks == S2.marks;
}

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

void Student::displayResult()
{
    cout << "\n...Result..." << endl;
    cout << "Name : " << firstName << " " << lastName << endl
         << "USN : " << usn << endl
         << "Marks : " << marks << endl;
}

void Student::getQuestions(string quesFile)
{
    fstream question, answerFile;
    question.open(quesFile);
    answerFile.open("fillBlanksAns.txt");
    string ques, correctAnswer;
    while (getline(question, ques))
    {
        cout << ques << "\n";
        cin >> studentAnswer;
        while (getline(answerFile, correctAnswer))
        {
            if (correctAnswer == studentAnswer)
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
    string ques, opts, correctAnswer;
    while (getline(question, ques))
    {
        cout << ques << "\n";
        while (getline(option, opts))
        {

            cout << opts << "\n";
            cin >> studentAnswer;
            while (getline(answerFile, correctAnswer))
            {
                if (correctAnswer == studentAnswer)
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
    int testChoice, numOfStu = 2;
    cout << "Enter your choice for the examination \n\n1: Quiz\n2: Fill In the blanks\n"
         << endl;
    cin >> testChoice;
    if (testChoice == 1)
    {
        QuizStudent Q[2];
        for (int i = 0; i < numOfStu; i++)
        {
            Q[i].readStudentDetails();
            Q[i].getQuestions("questions.txt", "options.txt");
            Q[i].displayResult();
            Q[i].saveResult();
        }
        if (Q[0] < Q[1])
            cout << "Student 1 got higher marks. " << endl;
        else if (Q[0] == Q[1])
            cout << "Both got the same mark. " << endl;
        else
            cout << "Student 2 got higher marks. " << endl;
    }
    else if (testChoice == 2)
    {
        FillInTheBlanksStudent F[2];
        for (int i = 0; i < numOfStu; i++)
        {
            F[i].readStudentDetails();
            F[i].getQuestions("fillBlanksQues.txt");
            F[i].displayResult();
            F[i].saveResult();
        }
        if (F[0] < F[1])
            cout << "Student 1 got higher marks. " << endl;
        else if (F[0] == F[1])
            cout << "Both got the same mark. " << endl;
        else
            cout << "Student 2 got higher marks. " << endl;
    }
}

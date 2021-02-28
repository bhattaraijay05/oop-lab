#include <iostream> //for providing basic input output functionality to the program
#include <fstream>  //for file handling
#include <string>   //for storing the strings
using namespace std;
string department, semester;

//class Student is the parent class
class Student
{
    string firstName, lastName, studentAnswer, usn;
    int marks = 0;

public:
    void readStudentDetails();
    void getQuestions(string, string);         //Function Overloading
    void getQuestions(string, string, string); //Function Overloading
    void displayResult();
    void saveResult();
    friend bool operator<(Student, Student);  //friend function and operator overloading
    friend bool operator==(Student, Student); //friend function and operator overloading
};

//QuizStudent class would be the inherited class from class student for getting and storing quiz questions
class QuizStudent : public Student //Inheritance
{
public:
    void getQuestions(string ques, string opt, string ans) //Function Overriding
    {
        cout << "Your Questions" << endl;
        Student::getQuestions(ques, opt, ans);
    }
};

//FillInTheBlanksStudent class would be the inherited class from class student for getting and storing fill in the blanks questions
class FillInTheBlanksStudent : public Student //Inheritance
{
public:
    void getQuestions(string ques, string ans) //Function Overriding
    {
        cout << "\nYour Questions" << endl;
        Student::getQuestions(ques, ans);
    }
};
//Operator overloading to check the highest marks between two students
bool operator<(Student S1, Student S2)
{
    return S1.marks < S2.marks;
}
//Operator overloading to check the if both students got equal marks
bool operator==(Student S1, Student S2)
{
    return S1.marks == S2.marks;
}
//This method would be responsible for reading the student details
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
//This method saveResult will be called to save the student result inside a file
void Student::saveResult()
{
    fstream file;
    file.open(usn, fstream::out); //the method (open) called from the library fstream is responsible for creating a file based on the student's name and storing the result
    file << "Department : " << department << endl
         << "Semester : " << semester << endl
         << "Name : " << firstName << " " << lastName << endl
         << "USN : " << usn << endl
         << "Marks : " << marks << endl;
    file.close();
}
//displayResult method will be called after giving the exam to display the total mark of the student
void Student::displayResult()
{
    cout << "\n...Result..." << endl;
    cout << "Department : " << department << endl
         << "Semester : " << semester << endl
         << "Name : " << firstName << " " << lastName << endl
         << "USN : " << usn << endl
         << "Marks : " << marks << endl;
}
//The important one-> this function for getting the question specifically this will call the quesfile and answer file for fill in the blanks type of question
void Student::getQuestions(string quesFile, string ansFile)
{
    fstream question, answerFile;
    question.open(quesFile);
    answerFile.open(ansFile);
    //again the method (open) opens the question file and answer file, diaplay the question file and compare the user answer with correct answer
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
// this is the  function overloading for getQuestions for getting the question specifically this will call the quesfile,option file and answer file for quiz type of question
void Student::getQuestions(string quesFile, string opFile, string ansFile)
{
    fstream question, option, answerFile;
    question.open(quesFile);
    answerFile.open(ansFile);
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

void takeTest()
{
    int testChoice, numOfStu = 2;
    cout << "Enter your choice for the examination \n\n1: MCQ Question\n2: Fill In the blanks\n"
         << endl;
    cin >> testChoice;
    if (testChoice == 1)
    {
        QuizStudent Q[2];
        for (int i = 0; i < numOfStu; i++)
        {
            Q[i].readStudentDetails();
            Q[i].getQuestions("questions.txt", "options.txt", "answers.txt");
            Q[i].displayResult();
            Q[i].saveResult();
        }
        if (Q[0] < Q[1])
            cout << "\n\nStudent 2 got higher marks. " << endl;
        else if (Q[0] == Q[1])
            cout << "\n\nBoth got the same mark. " << endl;
        else
            cout << "\n\nStudent 1 got higher marks. " << endl;
    }
    else if (testChoice == 2)
    {
        FillInTheBlanksStudent F[2];
        for (int i = 0; i < numOfStu; i++)
        {
            F[i].readStudentDetails();
            F[i].getQuestions("fillBlanksQues.txt", "fillBlanksAns.txt");
            F[i].displayResult();
            F[i].saveResult();
        }
        if (F[0] < F[1])
            cout << "\n\nStudent 2 got higher marks. " << endl;
        else if (F[0] == F[1])
            cout << "\n\nBoth got the same mark. " << endl;
        else
            cout << "\n\nStudent 1 got higher marks. " << endl;
    }
}

void selectSem(int semChoice)
{
    try //try catch block to throw exception if the user input is more than 3 semester
    {
        cout << "Enter your semester \n1:3rd\n2:4th\n3:5th\n"
             << endl;
        cin >> semChoice;

        if (semChoice <= 3)
        {
            if (semChoice == 1)
            {
                cout << "Your selected semester is 3rd" << endl;
                semester = "3rd";
                takeTest();
            }
            else if (semChoice == 2)
            {

                cout << "Your selected semester is 4th" << endl;
                semester = "4th";
                takeTest();
            }
            else
            {
                cout << "Your selected semester is 5th" << endl;
                semester = "5th";
                takeTest();
            }
        }
        else
        {
            throw(semChoice);
        }
    }
    catch (int myChoice)
    {
        cout << "Access denied - You can only select 3rd, 4th and 5th semester.\n";
        cout << "Selected Semester is: " << myChoice << endl;
    }
}

template <typename T> //Usage of templates
T myDept(T dep)
{
    return dep;
}

int main()
{
    bool dothis = false;
    do
    {
        int departmentChoice, semChoice;
        cout << "Enter your department \n1:Information Science and Engineering \n2:Mechanical Engineering  \n3:Civil Engineering \n4:Computer Science and Engineering\n ";
        cin >> departmentChoice;

        if (departmentChoice == 1)
        {
            cout << myDept<string>("Your selected branch is Information Science and Engineering") << endl;
            department = "Information Science and Engineering";
            selectSem(semChoice);
        }
        else if (departmentChoice == 2)
        {
            cout << myDept<string>("Your selected branch is Mechanical Engineering") << endl;
            department = "Mechanical Engineering";
            selectSem(semChoice);
        }
        else if (departmentChoice == 3)
        {
            cout << myDept<string>("Your selected branch is Civil Engineering") << endl;
            department = "Civil Engineering";
            selectSem(semChoice);
        }
        else if (departmentChoice == 4)
        {
            cout << myDept<string>("Your selected branch is Computer Science and Engineering") << endl;
            department = "Computer Science and Engineering";
            selectSem(semChoice);
        }
        else
        {
            cout << "Enter valid choice" << endl;
            dothis = true;
        }
    } while (dothis);
}

// Question Number 17
// Write a program to find the  addition of a matrix using friend function and with member functions to read and display the matrix.
#include <iostream>
using namespace std;

class Matrix
{
    int matrix[100][100];
    int rowSize, colSize;

public:
    void enterData();
    void displayData();
    friend Matrix operator+(Matrix, Matrix);
    void addMatrix(Matrix, Matrix);
};

void Matrix::enterData()
{
    int i, j;
    cout << "\n Enter the number of rows in the matrix: " << endl;
    cin >> rowSize;
    cout << "Enter the number of columns in the matrix: " << endl;
    cin >> colSize;
    cout << "Enter the data for rows and columns: " << endl;
    for (i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
            cin >> matrix[i][j];
    }
}

void Matrix::displayData()
{
    int i, j;
    for (i = 0; i < rowSize; i++)
    {
        cout << "  " << endl;
        for (j = 0; j < colSize; j++)
            cout << "  " << matrix[i][j];
    }
}

Matrix operator+(Matrix m1, Matrix m2)
{
    Matrix m3;
    cout << "\nSum of two matrix is :\n"
         << endl;
    for (int i = 0; i < m1.rowSize; i++)
    {
        cout << "  " << endl;
        for (int j = 0; j < m1.colSize; j++)
        {
            m3.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            cout << "   " << m3.matrix[i][j];
        }
    }
    return m3;
}

//modification
void Matrix::addMatrix(Matrix m1, Matrix m2)
{
    Matrix m3;
    cout << "\nSum of two matrix is :\n"
         << endl;
    for (int i = 0; i < m1.rowSize; i++)
    {
        cout << "  " << endl;
        for (int j = 0; j < m1.colSize; j++)
        {
            m3.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            cout << "   " << m3.matrix[i][j];
        }
    }
}
int main()
{
    Matrix firstMatrix, secondMatrix, addition;
    firstMatrix.enterData();
    firstMatrix.displayData();
    secondMatrix.enterData();
    secondMatrix.displayData();
    // (firstMatrix + secondMatrix);
    addition.addMatrix(firstMatrix, secondMatrix);

    return 0;
}
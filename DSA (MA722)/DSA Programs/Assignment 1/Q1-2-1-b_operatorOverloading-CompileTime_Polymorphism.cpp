// Program demonstrating Compile time Polymorphism in c++;
// (b) Operator Overloading 
// Roll No. 202cd005
// Assingment 1
#include<iostream>
using namespace std;
class Matrix
{
    private:
    int** mat;
    int rows,columns;
    public:
    Matrix()            // Default Constructor
    {
        rows=0;
        columns=0;
    }
    Matrix(int r, int c) // Parametric Constructor
    {
        this->rows = r;
        this->columns = c;
        mat = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new int[columns];
            for (int j = 0; j < columns; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    void matrixIN(int r, int c)
    {
        this->rows = r;
        this->columns = c;
        cout << "Enter matrix elements row-wise" << endl;
        mat = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new int[columns];
            for (int j = 0; j < columns; j++)
            {
                if (i == 0 && j == 0)
                {
                    cout << "Enter First element: ";
                    cin >> mat[i][j];
                }
                else
                {
                    cout << "Enter next Element: ";
                    cin >> mat[i][j];
                }
            }
        }
    }
    void matrixOUT(int r, int c)
    {
        this->rows = r;
        this->columns = c;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
    Matrix operator+(Matrix m) // overloading + operator for matrix addition
    {
        this->rows = m.rows;
        this->columns = m.columns;
        Matrix temp(m.rows, m.columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                temp.mat[i][j] = this->mat[i][j] + m.mat[i][j];
            }
        }
        return temp;
    }
    Matrix operator-(Matrix m) // overloading - operator for matrix subtraction
    {

        this->rows = m.rows;
        this->columns = m.columns;
        Matrix temp(m.rows, m.columns);
        for (int i = 0; i < temp.rows; i++)
        {
            for (int j = 0; j < temp.columns; j++)
            {
                temp.mat[i][j] = this->mat[i][j] - m.mat[i][j];
            }
        }
        return temp;
    }
};
int main()
{
    cout << "Demonstration of Operator overloading using Matrix Operations " << endl;
    Matrix m1,m2,m3,m4;
    cout << "Enter elements of first Matrix " <<endl;
    m1.matrixIN(2,2);
    cout << "Enter elements of second Matrix " <<endl;
    m2.matrixIN(2,2);
    cout << "Matrix Addition is " << endl;
    m3=m1+m2;
    m3.matrixOUT(2,2);
    cout << "Matrix subtraction is " << endl;
    m4=m1-m2;
    m4.matrixOUT(2,2);
    return 0;
}
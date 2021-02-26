// Matrix operations with operator overloading
// Roll No. 202cd005

#include <iostream>
#include <limits>
#include<stdlib.h>
using namespace std;
template <class T>
class Matrix
{
private:
    int rows, columns, x, y;
    T **mat, **sparseMatrix;

public:
    Matrix()
    {
        rows = 0;
        columns = 0;
        x = 0;
        y = 0;
    }
    Matrix(int r, int c)
    {
        this->rows = r;
        this->columns = c;
        mat = new T *[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new T[columns];
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
        mat = new T *[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new T[columns];
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
    T &operator()(int i, int j) const
    {
        return mat[i - 1][j - 1];
    }
    Matrix operator+(Matrix m)
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
    Matrix operator-(Matrix m)
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
    Matrix operator*(Matrix m)
    {
        this->rows = m.rows;
        this->columns = m.columns;
        Matrix temp(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                for (int k = 0; k < rows; k++)
                {
                    temp.mat[i][j] += this->mat[i][k] * m.mat[k][j];
                }
            }
        }
        return temp;
    }
    Matrix elementwisemultiplication(Matrix m)
    {
        this->rows = m.rows;
        this->columns = m.columns;
        Matrix temp(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                temp.mat[i][j] += this->mat[i][j] * m.mat[i][j];
            }
        }
        return temp;
    }
    Matrix Transpose(Matrix m)
    {
        this->rows = m.rows;
        this->columns = m.columns;
        Matrix temp(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                temp.mat[i][j] = this->mat[j][i];
            }
        }
        return temp;
    }
    bool checkSparse()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (mat[i][j] == 0)
                {
                    x++;
                }
                else
                {
                    y++;
                }
            }
        }
        if (x > y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void setSparse()
    {
        int c = y;
        int k = 0;
        sparseMatrix = new T *[3];
        for (int i = 0; i < 3; i++)
        {
            sparseMatrix[i] = new T[c];
            for (int j = 0; j < c; j++)
            {
                sparseMatrix[i][j] = 0;
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
                if (mat[i][j] != 0)
                {
                    sparseMatrix[0][k] = i;
                    sparseMatrix[1][k] = j;
                    sparseMatrix[2][k] = mat[i][j];
                    k++;
                }
        }
    }
    void displaySparse()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cout << sparseMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void generalBlockforMatrixOperationsInMainFuction(Matrix m1, Matrix m2, Matrix m3, Matrix m4)
    {
        int r1, c1, r2, c2, s;
        char ch;
        cout << "Enter number of rows of first matrix: ";
        cin >> r1;
        cout << "Enter number of columns of first matrix: ";
        cin >> c1;
        if (r1 <= 0 || c1 <= 0 || isdigit(r1) == true || isdigit(c1) == true)
        {
            cout << "Number of rows and columns should be positive intergers";
        }
        else
        {
            cout << "Enter elements of first matrix row-wise: " << endl;
            m1.matrixIN(r1, c1);
        }
        cout << "Enter number of rows of second matrix: ";
        cin >> r2;
        cout << "Enter number of columns of second matrix: ";
        cin >> c2;
        if (r2 <= 0 || c2 <= 0 || isdigit(r2) == true || isdigit(c2) == true)
        {
            cout << "Number of rows and columns should be positive intergers" << endl;
        }
        else
        {
            cout << "Enter elements of second matrix row-wise: " << endl;
            m2.matrixIN(r2, c2);
        }
        do
        {
            cout << "1.Addition\n2.Subtraction\n3.Multiplication\n4.Element wise multiplication\n5.Transpose\n6.Check if Sparse or not\n7.Clear Screen\n8.Go To previous Menu" << endl;
            cout << "Which operation do you want to perform?: ";
            cin >> s;
            switch (s)
            {
            case 1:
            {
                if (r1 == r2 && c1 == c2)
                {
                    m3 = m1 + m2;
                    cout << "Matrix addition is " << endl;
                    m3.matrixOUT(r1, c1);
                }
                else
                {
                    cout << "Matrix addition cannot be done because matrices are of different size." << endl;
                }
                break;
            }
            case 2:
            {
                if (r1 == r2 && c1 == c2)
                {
                    m3 = m1 - m2;
                    cout << "Matrix subtraction is " << endl;
                    m3.matrixOUT(r1, c1);
                }
                else
                {
                    cout << "Matrix subtraction cannot be done because matrices are of different size." << endl;
                }
                break;
            }
            case 3:
            {
                if (c1 = r2)
                {
                    m3 = m1 * m2;
                    cout << "Matrix multiplication is " << endl;
                    m3.matrixOUT(r1, c2);
                }
                else
                {
                    cout << "Matrix multiplication cannot be done.\nCheck size of matrices." << endl;
                }
                break;
            }
            case 4:
            {
                if (r1 == r2 && c1 == c2)
                {
                    m3 = m1.elementwisemultiplication(m2);
                    cout << "Matrix Element wise multiplication is " << endl;
                    m3.matrixOUT(r1, c1);
                }
                else
                {
                    cout << "Element wise multiplication cannot be done.\nMatrices are of different size." << endl;
                }
                break;
            }
            case 5:
            {
                cout << "Transpose of first matrix is: " << endl;
                m3 = m1.Transpose(m1);
                m3.matrixOUT(c1, r1);
                cout << "Transpose of second matrix is: " << endl;
                m4 = m2.Transpose(m2);
                m4.matrixOUT(c2, r2);
                break;
            }
            case 6:
            {
                if (m1.checkSparse() == true)
                {
                    cout << "First Matrix is a sparse matrix." << endl;
                    m1.setSparse();
                    m1.displaySparse();
                }
                else if (m1.checkSparse() == false)
                {
                    cout << "First Matrix is not a sparse matrix." << endl;
                }
                if (m2.checkSparse() == true)
                {
                    cout << "Second matrix is a sparse matrix." << endl;
                    m2.setSparse();
                    m2.displaySparse();
                }
                else if (m2.checkSparse() == false)
                {
                    cout << "Second matrix is not a sparse matrix." << endl;
                }
                break;
            }
            case 7:
            {
                system("clear");
                break;
            }
            case 8:
            {
                break;
            }
            default:
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                cout << "Invalid input.\nTry again! :)" << endl;
                break;
            }
            }
        }while(s!=8);
    }
};
int main()
{
    char ch;
    int s;
    do
    {
        cout << "\n=====================================================================================" << endl;
        cout << "************************* Matrix Operations using 2D Array **************************" << endl;
        cout << "=====================================================================================" << endl;
        cout << "\nSelect Data type: " << endl;
        cout << "1.INT      2.DOUBLE        3.FLOAT        4.Clear Screen       5.End Program" << endl;
        cout << ">";
        cin >> s;
        if (s == 1)
        {
            cout << "Selected data type: INT" << endl;
            Matrix<int> m1, m2, m3, m4, callobj;
            callobj.generalBlockforMatrixOperationsInMainFuction(m1, m2, m3, m4);
        }
        else if (s == 2)
        {
            cout << "Selected data type: DOUBLE" << endl;
            Matrix<double> m1, m2, m3, m4, callobj;
            callobj.generalBlockforMatrixOperationsInMainFuction(m1, m2, m3, m4);
        }
        else if (s == 3)
        {
            cout << "Selected data type: FLOAT" << endl;
            Matrix<float> m1, m2, m3, m4, callobj;
            callobj.generalBlockforMatrixOperationsInMainFuction(m1, m2, m3, m4);
        }
        else if(s==4)
        {
            system("clear");
        }
        else if(s==5)
        {
            cout << "\nProgram Ended"<< endl;
            cout << "\n************************************************************************************" << endl;
            break;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            cout << "Invalid Input!\nTry Again:)" << endl;
        }
    }while(s!=5);
    return 0;
}
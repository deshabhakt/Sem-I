// Sparse Matrix operations with operator overloading
// Roll No. 202cd005

#include <iostream>
#include <limits>
using namespace std;
template <class T>
class Sparse
{
private:
    int n_rows, n_columns, s_columns, x, y;
    T **mat, **sparsemat;
public:
    Sparse()
    {
        n_rows = 0;
        n_columns = 0;
        s_columns = 0;
        x = 0;
        y = 0;
    }
    Sparse(int rows, int columns)
    {
        this->n_rows = rows;
        this->n_columns = columns;
        mat = new T *[this->n_rows];
        for (int i = 0; i < this->n_rows; i++)
        {
            mat[i] = new T[this->n_columns];
            for (int j = 0; j < this->n_columns; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    Sparse(int columns)
    {
        this->s_columns = columns;
        sparsemat = new T *[3];
        for (int i = 0; i < 3; i++)
        {
            sparsemat[i] = new T[this->s_columns];
            for (int j = 0; j < this->s_columns; j++)
            {
                sparsemat[i][j] = 0;
            }
        }
    }
    // ~Sparse()
    // {
    //     delete [] mat;
    //     delete [] sparsemat;
    // }
    void sparseMatrixIN(int columns)
    {
        this->s_columns = columns;
        sparsemat = new T *[3];
        for (int i = 0; i < 3; i++)
        {
            sparsemat[i] = new T[this->s_columns];
            for (int j = 0; j < this->s_columns; j++)
            {
                sparsemat[i][j] = 0;
            }
        }
        sparsemat = new T *[3];
        for (int i = 0; i < 3; i++)
        {
            sparsemat[i] = new T[this->s_columns];
            for (int j = 0; j < this->s_columns; j++)
            {
                if (i == 0 && j == 0)
                {
                    cout << "Enter First element: ";
                    cin >> sparsemat[i][j];
                }
                else
                {
                    cout << "Enter next Element: ";
                    cin >> sparsemat[i][j];
                }
            }
        }
    }
    void normalMatrixIN(int rows, int columns)
    {
        this->n_rows = rows;
        this->n_columns = columns;
        mat = new T *[this->n_rows];
        for (int i = 0; i < this->n_rows; i++)
        {
            mat[i] = new T[this->n_columns];
            for (int j = 0; j < this->n_columns; j++)
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
    void displayNormalMatrix()
    {
        for (int i = 0; i < this->n_rows; i++)
        {
            for (int j = 0; j < this->n_columns; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    void displaySparseMatrix(Sparse s)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < s.s_columns; j++)
            {
                cout << s.sparsemat[i][j] << " ";
            }
            cout << endl;
        }
    }
    void displaySparseMatrix()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < this->s_columns; j++)
            {
                cout << sparsemat[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool checkSparse()
    {
        for (int i = 0; i < this->n_rows; i++)
        {
            for (int j = 0; j < this->n_columns; j++)
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
        int k = 0;
        this->s_columns = y;
        sparsemat = new T *[3];
        for (int i = 0; i < 3; i++)
        {
            sparsemat[i] = new T[this->s_columns];
            for (int j = 0; j < this->s_columns; j++)
            {
                sparsemat[i][j] = 0;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < this->s_columns; j++)
                if (mat[i][j] != 0)
                {
                    sparsemat[0][k] = i;
                    sparsemat[1][k] = j;
                    sparsemat[2][k] = mat[i][j];
                    k++;
                }
        }
    }
    int findNumberOfRows()
    {
        int temp = 0;
        for (int i = 0; i < this->s_columns - 1; i++)
        {
            if (sparsemat[0][i] > sparsemat[0][i + 1])
            {
                temp = sparsemat[0][i];
            }
            else
            {
                temp = sparsemat[0][i + 1];
            }
        }
        return temp + 1;
    }
    int findNumberOfColumns()
    {
        int temp = 0;
        for (int i = 0; i < this->s_columns - 1; i++)
        {
            if (sparsemat[1][i] > sparsemat[1][i + 1])
            {
                temp = sparsemat[1][i];
            }
            else
            {
                temp = sparsemat[1][i + 1];
            }
        }
        return temp + 1;
    }
    void convertToNormalMatrix(int rows, int columns)
    {
        T **convertedToNormal = new T *[rows];
        for (int i = 0; i < rows; i++)
        {
            convertedToNormal[i] = new T[columns];
            for (int j = 0; j < columns; j++)
            {
                convertedToNormal[i][j] = 0;
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (sparsemat[0][j] == i && sparsemat[1][j] == j)
                {
                    convertedToNormal[i][j] = sparsemat[2][j];
                }
            }
        }
        cout << "Converted to Normal Matrix: " << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << convertedToNormal[i][j] << " ";
            }
            cout << endl;
        }
    }
    Sparse operator+(Sparse s)
    {
        Sparse temp(s.s_columns);
        int i = 0, j = 0, k = 0;
        while (i < this->s_columns && j < s.s_columns)
        {
            if (sparsemat[0][i] > s.sparsemat[0][j] || sparsemat[0][i] == s.sparsemat[0][j] && sparsemat[1][i] > s.sparsemat[1][j])
            {
                temp.sparsemat[0][k] = s.sparsemat[0][j];
                temp.sparsemat[1][k] = s.sparsemat[1][j];
                temp.sparsemat[2][k] = s.sparsemat[2][j];
                j++;
            }
            else if (sparsemat[0][i] < s.sparsemat[0][j] || sparsemat[0][i] == s.sparsemat[0][j] && sparsemat[1][i] < s.sparsemat[1][j])
            {
                temp.sparsemat[0][k] = sparsemat[0][i];
                temp.sparsemat[1][k] = sparsemat[1][i];
                temp.sparsemat[2][k] = sparsemat[2][i];
                i++;
            }
            else
            {
                temp.sparsemat[0][k] = sparsemat[0][i];
                temp.sparsemat[1][k] = sparsemat[1][i];
                temp.sparsemat[2][k] = sparsemat[2][i] + s.sparsemat[2][j];
                i++;
                j++;
            }
            k++;
        }
        while (i < this->s_columns)
        {
            temp.sparsemat[0][k] = sparsemat[0][i];
            temp.sparsemat[1][k] = sparsemat[1][i];
            temp.sparsemat[2][k] = sparsemat[2][i];
            i++;
            k++;
        }
        while (j < s.s_columns)
        {
            temp.sparsemat[0][k] = s.sparsemat[0][j];
            temp.sparsemat[1][k] = s.sparsemat[1][j];
            temp.sparsemat[2][k] = s.sparsemat[2][j];
            j++;
            k++;
        }
        temp.s_columns = k;
        return temp;
    }
    Sparse operator-(Sparse s)
    {
        Sparse temp(s.s_columns);
        int i = 0, j = 0, k = 0;
        while (i < this->s_columns && j < s.s_columns)
        {
            if (sparsemat[0][i] > s.sparsemat[0][j] || sparsemat[0][i] == s.sparsemat[0][j] && sparsemat[1][i] > s.sparsemat[1][j])
            {
                temp.sparsemat[0][k] = s.sparsemat[0][j];
                temp.sparsemat[1][k] = s.sparsemat[1][j];
                temp.sparsemat[2][k] = -s.sparsemat[2][j];
                j++;
            }
            else if (sparsemat[0][i] < s.sparsemat[0][j] || sparsemat[0][i] == s.sparsemat[0][j] && sparsemat[1][i] < s.sparsemat[1][j])
            {
                temp.sparsemat[0][k] = sparsemat[0][i];
                temp.sparsemat[1][k] = sparsemat[1][i];
                temp.sparsemat[2][k] = -sparsemat[2][i];
                i++;
            }
            else
            {
                temp.sparsemat[0][k] = sparsemat[0][i];
                temp.sparsemat[1][k] = sparsemat[1][i];
                temp.sparsemat[2][k] = sparsemat[2][i] - s.sparsemat[2][j];
                i++;
                j++;
            }
            k++;
        }
        while (i < this->s_columns)
        {
            temp.sparsemat[0][k] = sparsemat[0][i];
            temp.sparsemat[1][k] = sparsemat[1][i];
            temp.sparsemat[2][k] = -sparsemat[2][i];
            i++;
            k++;
        }
        while (j < s.s_columns)
        {
            temp.sparsemat[0][k] = s.sparsemat[0][j];
            temp.sparsemat[1][k] = s.sparsemat[1][j];
            temp.sparsemat[2][k] = -s.sparsemat[2][j];
            j++;
            k++;
        }
        temp.s_columns = k;
        return temp;
    }
    Sparse elementwisemultiplication(Sparse s)
    {
        Sparse temp(s.s_columns);
        int i = 0, j = 0, k = 0;
        while (i < this->s_columns && j < s.s_columns)
        {
            if (sparsemat[0][i] > s.sparsemat[0][j] || sparsemat[0][i] == s.sparsemat[0][j] && sparsemat[1][i] > s.sparsemat[1][j])
            {
                temp.sparsemat[0][k] = s.sparsemat[0][j];
                temp.sparsemat[1][k] = s.sparsemat[1][j];
                temp.sparsemat[2][k] = 0;
                j++;
            }
            else if (sparsemat[0][i] < s.sparsemat[0][j] || sparsemat[0][i] == s.sparsemat[0][j] && sparsemat[1][i] < s.sparsemat[1][j])
            {
                temp.sparsemat[0][k] = sparsemat[0][i];
                temp.sparsemat[1][k] = sparsemat[1][i];
                temp.sparsemat[2][k] = 0;
                i++;
            }
            else
            {
                temp.sparsemat[0][k] = sparsemat[0][i];
                temp.sparsemat[1][k] = sparsemat[1][i];
                temp.sparsemat[2][k] = sparsemat[2][i] * s.sparsemat[2][j];
                i++;
                j++;
            }
            k++;
        }
        while (i < this->s_columns)
        {
            temp.sparsemat[0][k] = sparsemat[0][i];
            temp.sparsemat[1][k] = sparsemat[1][i];
            temp.sparsemat[2][k] = 0;
            i++;
            k++;
        }
        while (j < s.s_columns)
        {
            temp.sparsemat[0][k] = s.sparsemat[0][j];
            temp.sparsemat[1][k] = s.sparsemat[1][j];
            temp.sparsemat[2][k] = 0;
            j++;
            k++;
        }
        temp.s_columns = k;
        return temp;
    }
    Sparse Transpose()
    {
        Sparse temp(s_columns);
        for (int i = 0; i < this->s_columns; i++)
        {
            temp.sparsemat[0][i] = sparsemat[1][i];
            temp.sparsemat[1][i] = sparsemat[0][i];
            temp.sparsemat[2][i] = sparsemat[2][i];
        }
        return temp;
    }
    void generalSwitchCaseBlock(Sparse s1, Sparse s2, Sparse s3, Sparse s4)
    {
        int user_input, rows, columns;
        char ch;
        do
        {
            cout << "1.Normal Matrix to Sparse Matrix conversion\n2.Sparse Matrix to Normal Matrix Conversion\n3.Check if a matrix is sparse or not\n4.Sparse Matrix operations\n5.Clear Screen\n6.Previous Menu" << endl;
            cout << "Enter your choice: ";
            cin >> user_input;
            if (user_input == 1)
            {
                cout << "Enter number of rows of matrix: ";
                cin >> rows;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                cout << "Enter number of columns of matrix: ";
                cin >> columns;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                if (rows <= 0 && columns <= 0)
                {
                    cout << "Number of Rows and Columns should be positive integers." << endl;
                }
                else
                {
                    cout << "Enter Matrix Elements row-wise: " << endl;
                    s1.normalMatrixIN(rows, columns);
                    s1.displayNormalMatrix();
                    if (s1.checkSparse())
                    {
                        s1.setSparse();
                        cout << "Given Matrix after conversion to Sparse Matrix is: " << endl;
                        s1.displaySparseMatrix();
                    }
                    else
                    {
                        cout << "Conversion not possible.\nGiven matrix is not sparse matrix." << endl;
                    }
                }
            }
            else if (user_input == 2)
            {
                cout << "Enter number of columns in sparse matrix: ";
                cin >> columns;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                if (columns <= 0)
                {
                    cout << "Number of columns should be positive integer." << endl;
                }
                else
                {
                    cout << "Enter elements of sparse matrix row-wise:" << endl;
                    s1.sparseMatrixIN(columns);
                    s1.displaySparseMatrix();
                    rows = s1.findNumberOfRows();
                    columns = s1.findNumberOfColumns();
                    s1.convertToNormalMatrix(rows, columns);
                }
            }
            else if (user_input == 3)
            {
                cout << "Enter number of rows of matrix: ";
                cin >> rows;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                cout << "Enter number of columns of matrix: ";
                cin >> columns;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                if (rows <= 0 && columns <= 0)
                {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.clear();
                    cout << "Number of Rows and Columns should be positive integers." << endl;
                }
                else
                {
                    cout << "Enter Matrix Elements row-wise: " << endl;
                    s1.normalMatrixIN(rows, columns);
                    if (s1.checkSparse())
                    {
                        cout << "Given Matrix is a Sparse Matrix." << endl;
                    }
                    else
                    {
                        cout << "Given Matrix is not a Sparse Matrix." << endl;
                    }
                }
            }
            else if (user_input == 4)
            {
                int user_input_for_sp_operations, c1, c2;
                cout << "\n************ Perform Sparse Matrix operations with two Sparse Matrices *************" << endl;
                cout << "\nEnter number of columns of first sparse matrix:";
                cin >> c1;
                if (columns <= 0)
                {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.clear();
                    cout << "Number of columns should be positive integer." << endl;
                }
                else
                {
                    cout << "Enter elements of first sparse matrix row-wise:" << endl;
                    s1.sparseMatrixIN(c1);
                }
                cout << "Enter number of columns of second sparse matrix:";
                cin >> c2;
                if (columns <= 0)
                {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.clear();
                    cout << "Number of columns should be positive integer." << endl;
                }
                else
                {
                    cout << "Enter elements of second sparse matrix row-wise:" << endl;
                    s2.sparseMatrixIN(c2);
                }
                do
                {
                    cout << "Which operation do you want to perform?" << endl;
                    cout << "1.Addition\n2.Subtraction\n3.Dot multiplication\n4.Transpose\n5.Print Sparse Matrices\n6.Clear Screen\n7.Previous Menu" << endl;
                    cin >> user_input_for_sp_operations;
                    switch (user_input_for_sp_operations)
                    {
                    case 1:
                    {
                        s3 = s1 + s2;
                        cout << "Addition Sparse matrix is: " << endl;
                        s3.displaySparseMatrix(s3);
                        break;
                    }
                    case 2:
                    {
                        s3 = s1 - s2;
                        cout << "Subtraction Sparse matrix is: " << endl;
                        s3.displaySparseMatrix(s3);
                        break;
                    }
                    case 3:
                    {
                        s3 = s1.elementwisemultiplication(s2);
                        cout << "Dot multiplication Sparse matrix is: " << endl;
                        s3.displaySparseMatrix(s3);
                        break;
                    }
                    case 4:
                    {
                        do
                        {
                            cout << "1.Transpose of first sparse matrix\n2.Transpose of Second sparse matrix\n3.Transpose of both sparse matrices.\n4.Previous Menu\n>";
                            cin >> user_input;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin.clear();
                            switch (user_input)
                            {
                            case 1:
                            {
                                cout << "Transpose of first sparse matrix is:" << endl;
                                s3 = s1.Transpose();
                                s3.displaySparseMatrix();
                                break;
                            }
                            case 2:
                            {
                                cout << "Transpose of second sparse matrix is:" << endl;
                                s3 = s2.Transpose();
                                s3.displaySparseMatrix();
                                break;
                            }
                            case 3:
                            {
                                cout << "Transpose of first sparse matrix is:" << endl;
                                s3 = s1.Transpose();
                                s3.displaySparseMatrix();
                                cout << "Transpose of second sparse matrix is:" << endl;
                                s4 = s2.Transpose();
                                s4.displaySparseMatrix();
                                break;
                            }
                            default:
                            {
                                break;
                            }
                            }
                        } while (user_input != 4);
                        break;
                    }
                    case 5:
                    {
                        cout << "First sparse matrix is: " << endl;
                        s1.displaySparseMatrix();
                        cout << "Second sparse matrix is: " << endl;
                        s2.displaySparseMatrix();
                        break;
                    }
                    case 6:
                    {
                        system("clear");
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                } while (user_input_for_sp_operations != 7);
            }
            else if (user_input == 5)
            {
                system("clear");
            }
            else if (user_input == 6)
            {
                break;
            }
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                cout << "Invalid input!\nTry Again:)" << endl;
            }
            cout << "\n************************************************************************************" << endl;
        }while(user_input!=6);
    }
};
int main()
{
    char ch;
    int user_input_for_data_type;
    do
    {
        cout <<"\n====================================================================================="<<endl;
        cout <<"********************** Sparse Matrix Operations using 2D Array **********************"<<endl;
        cout <<"====================================================================================="<<endl;
        cout << "\nSelect Data type: " << endl;
        cout << "1.INT      2.DOUBLE        3.FLOAT     4.Clear Screen      5.Exit from program" << endl;
        cout << ">";
        cin >> user_input_for_data_type;
        if (user_input_for_data_type == 1)
        {
            cout << "Selected data type: INT" << endl;
            Sparse<int> s1, s2, s3, s4, callobj;
            callobj.generalSwitchCaseBlock(s1, s2, s3, s4);
        }
        else if (user_input_for_data_type == 2)
        {
            cout << "Selected data type: DOUBLE" << endl;
            Sparse<double> s1, s2, s3, s4, callobj;
            callobj.generalSwitchCaseBlock(s1, s2, s3, s4);
        }
        else if (user_input_for_data_type == 3)
        {
            cout << "Selected data type: FLOAT" << endl;
            Sparse<float> s1, s2, s3, s4, callobj;
            callobj.generalSwitchCaseBlock(s1, s2, s3, s4);
        }
        else if(user_input_for_data_type == 4)
        {
            system("clear");
        }
        else if(user_input_for_data_type == 5)
        {
            cout << "\nProgram Ended"<<endl;
            cout<<"\n====================================================================================="<<endl;
            break;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            cout <<"Invalid input\nTry Again."<<endl;
        }
    } while (user_input_for_data_type!=5);
    return 0;
}
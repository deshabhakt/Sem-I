// Program demonstrating Compile time Polymorphism in c++;
// (a) Function Overloading 
// Roll No. 202cd005
// Assingment 1
#include<iostream>
using namespace std;
class functionOverloadingDemo
{
    public:
    void print(int x)
    {
        cout << "Given Interger is " << x << endl;
    }
    void print(char x)
    {
        cout << "Given Character is " << x << endl;
    }
    void print(int x, int y)
    {
        cout << "Given intergers are " << x <<" and " << y << endl;
    }
    void print(string s)
    {
        cout << "Given string is " << s << endl;
    }
};
int main()
{
    functionOverloadingDemo overload;
    overload.print(5);      // assingns value to print(int x) function
    overload.print('X');    // assingns value to print(char x) function
    overload.print(10,15);  // assingns value to print(int x, int y) function
    overload.print("'Fuction overloading Demonstration'");    // assings value to print(string s) fuction
    return 0;
}
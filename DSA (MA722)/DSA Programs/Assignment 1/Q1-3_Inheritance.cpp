// Program on Demonstration of Inheritance
// Roll No. 202cd005
// Assingment 1
#include<iostream>
using namespace std;
class parent
{
    public:
    int x,y;
    void setX(int a)
    {
        x=a;
    }
};
class child : public parent
{
    public:
    void printX()
    {
        cout << "X = " << x << endl;
    }
};
int main()
{
    child c;
    c.setX(5);  // Calling Parent Class setX() function using child class object
    c.printX(); 
    return 0;
}
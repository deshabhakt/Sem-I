// Program on Demonstration of Runtime polymorphism (i.e. implementation of function overriding)
// Roll No. 202cd005
// Assignment 1
#include<iostream>
using namespace std;
class base
{
    public:
    virtual void print()
    {
        cout << "Base class print fuction called." << endl;
    }
    void  get()
    {
        cout << "Base class get function called." << endl;
    }
};
class derived : public base
{
    public:
    void print()
    {
        cout << "Derived class print function called."<< endl;
    }
    void get()
    {
        cout << "Derived class get function called."<< endl;
    }
};
int main()
{
    cout << "Demonstration of Runtime polymorphism (Function overriding)"<<endl;
    base *b;
    derived d;
    b=&d;
    b->print();  // As print() function of base class is declared as "virtual" hence it does not have execution
                 // Therefore, here derived class print() function overrides base class print() function.
    b->get();    // As get() function of base class is not declared as "virtual" hence it is execute.
    return 0;
}
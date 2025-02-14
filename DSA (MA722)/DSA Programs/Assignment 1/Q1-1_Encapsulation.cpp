// Program Demonstrating Encapsulation
// Roll No. 202cd005
// Assignment 1
#include<iostream>
using namespace std;
class encapdemo
{
    private:
    int x;
    public:
    void set(int a)
    {
        x=a;
    }
    void get()
    {
        cout << "x = " <<x<<endl;
    }
};
int main()
{
    encapdemo demo;  // creating object 'demo' of encapdemo 'class'.
    demo.set(5);     // setting x=5 using set function.
                     // As x is declared private, hence we cannot access it directly.
                     // We can only access it using function of encapdemo class.
    demo.get();      // printing x using get function.
    return 0;
}
// Program on demonstration of Abstraction
// Abstraction avoids code duplication and increases code reusibility
// Roll No. 202cd005
// Assingment 1
#include<iostream>
using namespace std;
#include <iostream> 
using namespace std; 
class abstractionDemo 
{ 
    private: 
        int a;
    public: 
        void set(int x) // function to set values of private members 
        { 
            a = x; 
        } 
        void display() 
        { 
            cout<<"a = " <<a << endl; 
        } 
}; 
int main()  
{ 
    abstractionDemo obj; 
    obj.set(10); 
    obj.display(); 
    return 0; 
} 


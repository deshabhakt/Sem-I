#include<iostream>
using namespace std;
long long fact(long long i)
{
    if(i==0)
    {
        return 1;
    }
    else if(i==1)
    {
        return 1;
    }
    else
    {
        return i*fact(i-1);
    }
}
int main()
{
    long long x=0;
    cout << "> ";
    cin >> x;
    long long y=fact(x);
    cout << "Factorial(x) is : "<< y <<endl;
    return 0;
}
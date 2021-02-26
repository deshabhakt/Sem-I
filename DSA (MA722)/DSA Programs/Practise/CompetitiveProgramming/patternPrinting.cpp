#include<iostream>
using namespace std;
void pattern(int n)
{
    cout << endl<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                cout << "*";
            else
            {
                cout << "0";
            }
            
        }
        cout << "*";
        for(int k=0;k<n;k++)
        {
            if((k+i)==n-1)
            {    
                cout << "*";
            }
            else 
            {
                cout << "0";
            }
        }
        cout << endl;
    }
    cout << endl  <<endl;
}
int main()
{
    pattern(5);
    pattern(10);
    pattern(20);
    return 0;
}
#include<iostream>
using namespace std;
void reverseArray(int ar[],int size)
{
    int i=0;
    int end=size-1;
    while(i<end)
    {
        int temp=ar[i];
        ar[i]=ar[end];
        ar[end]=temp;
        i++;end--;
    }
}
void reversewithbuiltinSwapfun(int ar[],int size)
{
    int i=0;
    int end=size-1;
    while(i<end)
    {
        swap(ar[i],ar[end]);
        i++;end--;
    }
}
void printArray(int ar[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
int main()
{
    int ar[]={1,2,3,4,5,6,7,8,9,10};
    int sz=sizeof(ar)/sizeof(ar[0]);
    printArray(ar,sz);
    reverseArray(ar,sz);
    printArray(ar,sz);
    reversewithbuiltinSwapfun(ar,sz);
    printArray(ar,sz);
    cout <<endl;
    return 0;
}
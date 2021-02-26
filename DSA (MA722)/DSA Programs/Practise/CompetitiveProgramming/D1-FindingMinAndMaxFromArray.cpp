#include<iostream>
using namespace std;
int arrayMin(int arr[],int size)
{
    int min=arr[0];
    for(int i=0;i<size;i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
        }
    }
    return min;
}
int arrayMax(int arr[],int size)
{
    int max=arr[0];
    for(int i=0;i<size;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    return max;
}
int main()
{
    int ar[]={10,25,16,48,6,32,49,235,64,8,321,5,12,4,5,21,5,21,3,44};
    int size=sizeof(ar)/sizeof(ar[0]);
    cout << "Min of array is "<< arrayMin(ar,size)<<endl;
    cout << "Max of array is "<< arrayMax(ar,size)<<endl;
    return 0;
}
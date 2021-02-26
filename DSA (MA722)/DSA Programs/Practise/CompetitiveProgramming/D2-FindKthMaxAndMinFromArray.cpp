#include<iostream>
using namespace std;
int arrayMin(int arr[],int size,int k)
{
    int min=arr[0];
    for(int i=0;i<size;i++)
    {
        if((min>arr[i])&&((i+1)%k==0))
        {
            min=arr[i];
        }
    }
    return min;
}
int arrayMax(int arr[],int size,int k)
{
    int max=arr[0];
    for(int i=0;i<size;i++)
    {
        if((max<arr[i])&&((i+1)%k==0))
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
    int k;
    cout <<"Finding kth Max and Min element from Array"<<endl;
    cout <<"Enter Value of k :";
    cin >> k;
    cout << "Min of array is "<< arrayMin(ar,size,k)<<endl;
    cout << "Max of array is "<< arrayMax(ar,size,k)<<endl;
    return 0;
}
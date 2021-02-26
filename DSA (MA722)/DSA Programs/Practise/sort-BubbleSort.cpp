// Complexeity O(n2)

#include<iostream>
using namespace std;
void bubbleSort(int a[],int size)
{
    int swapcount;
    for(int i=0;i<size-1;i++)
    {
        swapcount=0;
        for(int j=0;j<(size-i-1);j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                swapcount++;
            }
        }
        if(swapcount==0)
        {
            break;
        }
    }
}
void printArray(int arr[],int r)
{   
    int i=0;
    while(i<r)
    {
        cout << arr[i] <<" ";
        i++;
    }
    cout <<endl;
}
int main()
{
    int array[]={1,47,1,2,6,7,1,53,49,45,5,1,24,87};
    int size=sizeof(array)/sizeof(array[0]);
    bubbleSort(array,size);
    printArray(array,size);
    return 0;
}
#include<iostream>
using namespace std;

void InsertionSort(int arr[],int size)
{
    int i,key,j;
    for(int i=1;i<size;i++)
    {
        int key=arr[i];
        j=i-1;

        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j + 1] = key;  
    }
}
void InsertionSort(int arr[],int size)
{
    int i,j,key;
    for(i=1;i<size;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    
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
    InsertionSort(array,size);
    printArray(array,size);
    return 0;
}
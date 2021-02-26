#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r)
{
    int i=l;
    int k=l;
    int j=m+1;
    int merge[r+1];
    while(i<=m&&j<=r)
    {
        if(arr[i]<arr[j])
        {
            merge[k]=arr[i];
            i++;k++;
        }
        else
        {
            merge[k]=arr[j];
            j++;k++;
        }
    }
    while(i<=m)
    {
        merge[k]=arr[i];
        i++;k++;
    }
    while(j<=r)
    {
        merge[k]=arr[j];
        j++;k++;
    }
    for(int n=l;n<=r;n++)
    {
        arr[n]=merge[n];
    }
}
void mergeSort(int arr[],int l,int r)
{
    
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void printArray(int arr[],int r)
{   
    int i=0;
    while(i<=r)
    {
        cout << arr[i] <<" ";
        i++;
    }
    cout <<endl;
}
int main()
{
    int array[]={1,47,1,2,6,7,1,53,49,45,5,1,24,87};
    int size=sizeof(array)/sizeof(array[0])-1;
    mergeSort(array,0,size);
    printArray(array,size);
    return 0;
}
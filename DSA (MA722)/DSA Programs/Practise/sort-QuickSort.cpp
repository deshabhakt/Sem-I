#include<iostream>
using namespace std;
// int Partition(int arr[],int s,int e)
// {
//     int pivot=arr[e];
//     int pIndex=s;
//     for(int i=s;i<e;i++)
//     {
//         if(arr[i]<pivot)
//         {
//             int temp = arr[i];
//             arr[i]=arr[pIndex];
//             arr[pIndex]=temp;
//             pIndex++;
//         }
//     }
//     int temp = arr[e];
//     arr[e]=arr[pIndex];
//     arr[pIndex]=temp;
//     return pIndex;
// }
// void QuickSort(int arr[],int s,int e)
// {
//     if(s<e)
//     {
//         int p = Partition(arr,s,e);
//         QuickSort(arr,s,p-1);
//         QuickSort(arr,p+1,e);
//     }
// }
int Partition(int arr[],int s,int e)
{
    int pivot=arr[e];
    int pIndex=s;
    for(int i=s;i<e;i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[e],arr[pIndex]);
    return pIndex;
}
void QuickSort(int arr[],int s,int e)
{
    if(s<e)
    {
        int p=Partition(arr,s,e);
        QuickSort(arr,s,p-1);
        QuickSort(arr,p+1,e);
    }
}
void printArray(int arr[],int size)
{
    for(int i=0;i<=size;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int array[]={1,47,1,2};
    // int array[]={1,47,1,2,6,7,1,53,49,45,5,1,24,87};
    int size=sizeof(array)/sizeof(array[0])-1;
    QuickSort(array,0,size);
    printArray(array,size);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int Partition(int arr[],int s,int e)
{
    int pivot=arr[e];
    int pIndex=s;
    for(int i=s;i<e;i++)
    {
        if(arr[i]<pivot)
        {
            int temp = arr[i];
            arr[i]=arr[pIndex];
            arr[pIndex]=temp;
            pIndex++;
        }
    }
    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;
    return pIndex;
}
void QuickSort(int arr[],int s,int e)
{
    if(s<e)
    {
        int p = Partition(arr,s,e);
        QuickSort(arr,s,p-1);
        QuickSort(arr,p+1,e); 
    }
}

void printArray(int arr[],int r)
{
    for(int i=0;i<=r;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int array[]={1,25,4,7,1,23,11,4,65,68,7,123,4,76,5,123,222,45,6,87};
    int size = sizeof(array)/sizeof(int)-1;
    printArray(array,size);
    QuickSort(array,0,size);
    printArray(array,size);
    return 0;
}
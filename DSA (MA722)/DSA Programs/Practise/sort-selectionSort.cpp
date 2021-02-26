//intermediate results are useful to find smallest elements in list
//Not adaptive and not stable

#include<iostream>
using namespace std;

void SelectionSort(int arr[],int size)
{
    int i,j,k;
    for(i=0;i<size-1;i++)
    {
        for(j=k=i;j<size;j++)
        {
            if(arr[j]<arr[k])
            {
                k=j;
            }
        }
        swap(arr[i],arr[k]);
    }
}
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int array[]={1,47,1,2,6,7,1,53,49,45,5,1,24,87};
    int size=sizeof(array)/sizeof(array[0]);
    SelectionSort(array,size);
    printArray(array,size);
    return 0;
}
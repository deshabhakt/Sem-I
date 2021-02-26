#include<stdio.h>
#include<stdlib.h>
#define N 10
int dotProduct(int a[],int b[])
{
    int result=0;
    for(int i=0;i<N;i++)
    {
        result+=a[i]*b[i];
    }
    return result;
}
void printArray(int arr[], int r)
{
    for (int i = 0; i <r; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main()
{

}
// Printing Histogram from user input data (using bins)

#include<stdio.h>
int bin(int* arr, int arrsize,int binmin,int binmax)
{
    int bincount=1;
    int binmin=binmin;
    int binmax=binmax;
    for (int i=0;i<arrsize;i++)
    {
        if(binmax-arr[i]=>0 && arr[] )
        {
            bsize-=arr[i];
            continue;
        }
        else
        {
            bincount++;
            bsize=binsize;
            i--;
        }
    }
    return bincount;
}
int main()
{
    printf("Enter Array size :");
    int arrsize;
    scanf("%d",&arrsize);
    printf("Enter Elements one by one: \n");
    int a[arrsize];
    for(int i=0;i<arrsize;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter bin size: ");
    int binsize;
    scanf("%d",&binsize);
    int bincount;
    bincount=bin(a,arrsize,binsize);
    printf("Number of bins required are : %d", bincount);
    return 0;
}
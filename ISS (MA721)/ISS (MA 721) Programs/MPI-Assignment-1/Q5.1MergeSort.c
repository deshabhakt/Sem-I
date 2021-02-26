#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
void merge(int arr[],int l,int m, int r)
{
    int i=l,j=m+1,k=l;
    int temp[r+1];
    while(i<=m&&j<=r)
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;k++;
        }
        else
        {
            temp[k]=arr[j];
            j++;k++;
        }
    }
    while(i<=m)
    {
        temp[k]=arr[i];
        i++;k++;
    }
    while(j<=r)
    {
        temp[k]=arr[j];
        j++;k++;
    }
    for(int s=l;s<=r;s++)
    {
        arr[s]=temp[s];
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
    for(int i=0;i<=r;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
int main(int argc,char* argv[])
{
    int size,myrank;
    int N=atoi(argv[1]);  // tanking input from command line
    int array[N];
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % (N * 2);
    }
    int r=N-1;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    int localArray[N/size];
    MPI_Scatter(&array,(N/size),MPI_INT,&localArray,(N/size),MPI_INT,0,MPI_COMM_WORLD);
    double t1=MPI_Wtime();
    mergeSort(localArray,0,(r/size));
    double t2=MPI_Wtime();
    printf("\nSorted LOCAL ARRAY AT PROCESS %d is ",myrank);
    printArray(localArray,(r/size));
    printf("\nTime required for Process %d to Sort local array is %1.10f \n",myrank,(t2-t1));
    MPI_Gather(&localArray,(N/size),MPI_INT,&array,(N/size),MPI_INT,0,MPI_COMM_WORLD);
    if(myrank==0 && size >1)
    {
       double t3=MPI_Wtime();
       if(size!=1)
         mergeSort(array,0,r);
       double t4=MPI_Wtime();
       printf("\n\nSORTED GLOBAL ARRAY AT PROCESS %d is ",myrank);
       printArray(array,r);
       printf("\nTIME REQUIRED FOR PROCESS %d TO SORT LOCAL ARRAYS (RECEIVED FORM MPI_Gather()) is %1.10f \n",myrank, (t4-t3));
    }
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}

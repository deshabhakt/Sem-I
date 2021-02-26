#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

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

void printArray(int arr[], int r)
{
    for (int i = 0; i <r; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    int size, myrank;
    int N=atoi(argv[1]);  // tanking input from command line
    int array[N];
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % (N * 2);
    }
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    int localArray[N / size];
    MPI_Scatter(&array, (N / size), MPI_INT, &localArray, (N / size), MPI_INT, 0, MPI_COMM_WORLD);
    double t1 = MPI_Wtime();
    QuickSort(localArray, 0, (N / size));
    double t2 = MPI_Wtime();
    printf("\nSorted LOCAL ARRAY AT PROCESS %d is ",myrank);
    printArray(localArray, (N / size));
    printf("\nTime required for Process %d to Sort local array is %1.10f \n", myrank, (t2 - t1));
    MPI_Gather(&localArray, (N / size), MPI_INT, &array, (N / size), MPI_INT, 0, MPI_COMM_WORLD);
    if (myrank == 0 && size >1)
    {
        double t3 = MPI_Wtime();
        if (size != 1)
            QuickSort(array, 0, N);
        double t4 = MPI_Wtime();
        printf("\n\nSORTED GLOBAL ARRAY AT PROCESS %d is ",myrank);
        printArray(array, N);
        printf("\nTIME REQUIRED FOR PROCESS %d TO SORT LOCAL ARRAYS (RECEIVED FORM MPI_Gather()) is %1.10f \n", myrank, (t4 - t3));
    }
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}
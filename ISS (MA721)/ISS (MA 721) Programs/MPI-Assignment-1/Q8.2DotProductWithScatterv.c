#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define N 10
int dotProduct(int a[],int b[],int size)
{
    int result=0;
    for(int i=0;i<size;i++)
    {
        result+=a[i]*b[i];
    }
    return result;
}
void printArray(int arr[], int r,int myrank)
{
    printf("Vector at process %d is ",myrank);
    for (int i = 0; i <r; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main(int argv,char* argc[])
{
    int size,myrank,gresult;
    int a[N],b[N];
    int sum=0,result=0;
    MPI_Init(&argv,&argc);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    int sendcounts[]={4,6}; // Number of elements to be send to each processor
    int displs[]={0,4};     // relative to sendbuf from which to take the outgoing data to process i
    if (myrank == 0)
    {
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % (N * 2);
            b[i] = rand() % (N * 2);
        }
        
    }
    MPI_Barrier(MPI_COMM_WORLD);
    int c[sendcounts[myrank]],d[sendcounts[myrank]];
    MPI_Scatterv(&a,sendcounts,displs,MPI_INT,&c,sendcounts[myrank],MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatterv(&b,sendcounts,displs,MPI_INT,&d,sendcounts[myrank],MPI_INT,0,MPI_COMM_WORLD);
    double t1 = MPI_Wtime();
    for(int i=0;i<sendcounts[myrank];i++)
    {
        result+=c[i]*d[i];
    }
    double t2 = MPI_Wtime();
    printArray(c,sendcounts[myrank],myrank);
    printArray(d,sendcounts[myrank],myrank);
    printf("At process %d, dot product is %d.\n",myrank,result);
    printf("\nProcess: %d --> Time Required to find it's part of dot product : %1.10f \n", myrank, (t2 - t1));
    MPI_Reduce(&result,&gresult,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    double t3 = MPI_Wtime();
    if(myrank==0)
    {
        // printf("\nFirst vector is ");
        // printArray(a,N);
        // printf("\n");
        // printf("\nSecond vector is ");
        // printArray(b,N);
        // printf("\n");
        printf("\nFinal dot product is %d.\n",gresult);
        printf("\nProcess: %d --> Time Required to find it's part of dot product : %1.10f \n", myrank, (t3 - t2));
    }
    MPI_Finalize();
    return 0;    
}
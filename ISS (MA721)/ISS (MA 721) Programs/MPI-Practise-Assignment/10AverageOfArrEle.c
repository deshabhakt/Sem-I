#include<stdio.h>
#include<mpi.h>
int main(int argv,char *argc[])
{
    int myrank,size,n,sum;
    MPI_Init(&argv,&argc);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    int A[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int B[]={};
    n=sizeof(A)/sizeof(int);
    int x=(n/size);
    MPI_Scatter(&A,x,MPI_INT,&B,x,MPI_INT,0,MPI_COMM_WORLD);
    int localsum=0;
    for(int i=0;i<x;i++)
    {
        localsum+=B[i];
    }
    MPI_Reduce(&localsum,&sum,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
    if(myrank==0)
    {
        float average = (float)sum/n;
        printf("Average of Array elements is %0.4f",average);
    }
    MPI_Finalize();
    return 0;
}
// Minimum ele

#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) 
{
    int rank, size,n,lmin,gmin,x;
    int ArrIN[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
    int B[]={};
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    n=sizeof(ArrIN)/sizeof(int);
    x=n/size;
    MPI_Scatter(&ArrIN,x,MPI_INT,&B,x,MPI_INT,0,MPI_COMM_WORLD);
    lmin=B[0];
    for(int i=0;i<x;i++)
    {
        if(lmin>B[i])
        {
            lmin=B[i];
        }
    }
    printf("Local min of process %d is %d\n",rank,lmin);
    MPI_Reduce(&lmin,&gmin,size,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);
    if(rank==0)
    {        
        printf("Min of Entire array is %d\n",gmin);
    }
    MPI_Finalize();
    return 0;
}


#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

void printArray(int arr[], int r,int myrank)
{
    printf("Array at process %d is ",myrank);
    for (int i = 0; i <r; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main(int argc, char *argv[]) 
{
    int rank, size,lmax,gmax;
    int N=atoi(argv[1]);
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int newsize,scattersize;
    if((N%size)==0)
    {
        scattersize=(N/size);
    }
    else
    {
        scattersize=(N/size)+1;
    }
    newsize=scattersize*size;
    int ArrIN[newsize];
    for (int i = 0; i < newsize; i++)
    {
        if(i<N)
        {
            ArrIN[i] = rand()%(newsize*2 + 1);
        }
        else
        {
            ArrIN[i]=0;
        }
    }
    int B[scattersize];
    MPI_Scatter(&ArrIN,scattersize,MPI_INT,&B,scattersize,MPI_INT,0,MPI_COMM_WORLD);
    printArray(B,scattersize,rank);
    lmax=B[0];
    double t1=MPI_Wtime();
    for(int i=0;i<scattersize;i++)
    {
        if(lmax<B[i])
        {
            lmax=B[i];
        }
    }
    double t2=MPI_Wtime();
    printf("Local max of process %d is %d\n",rank,lmax);
    MPI_Reduce(&lmax,&gmax,1,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);
    double t3=MPI_Wtime();
    printf("Time required for process %d to find loacal max is %1.10f \n",rank,(t2-t1));
    if(rank==0)
    {        
        // printArray(temp,newsize,myrank);
        printf("\n\nMax of Entire array is %d\n\n",gmax);
        printf("Time required for process %d to calculate global max %1.10f \n",rank,(t3-t2));fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}



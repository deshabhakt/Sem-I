#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

void printArray(int arr[], int r,int myrank)
{
    printf("Array at process %d is ",myrank);
    for (int i = 0; i <r; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main(int argc,char* argv[])
{
    int size,myrank;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int N=atoi(argv[1]);    // Taking input from command line
    int scattersize;
    if((N%size)==0)
    {
        scattersize=(N/size);
    }
    else
    {
        scattersize=(N/size)+1;
    }
    int newsize=scattersize*size;
    int a[newsize];
    if(myrank==0)
    {
        for(int i=0;i<newsize;i++)
        {
            if(i<N)
            {
                a[i]=i+1;
            }
            else
            {
                a[i]=0;
            }
            
        }
    }
    MPI_Barrier(MPI_COMM_WORLD);
    int temp[scattersize];
    MPI_Scatter(&a,scattersize,MPI_INT,&temp,scattersize,MPI_INT,0,MPI_COMM_WORLD);
    double t1=MPI_Wtime();
    for(int i=0;i<scattersize;i++)
    {
        if(i!=0)
        {
            int t=temp[i];
            temp[i]=t+temp[i-1];
        }
    }
    double t2=MPI_Wtime();
    printf("\nProcesse: %d --> Time required  to perform PreFix Sum: %1.10f\n",myrank,(t2-t1));
    // printArray(temp,scattersize,myrank);
    int gArray[newsize];
    MPI_Gather(&temp,scattersize,MPI_INT,&gArray,scattersize,MPI_INT,0,MPI_COMM_WORLD);
        double t3=MPI_Wtime();
    if(myrank==0 && size>1)
    {
        for(int i=scattersize;i<N;i++)
        {
            {
                int t=gArray[i];
                gArray[i]=t+gArray[i-1];
            }
        }
        double t4=MPI_Wtime();
        
        printf("\nProcesse: %d --> Time required  to perform Final PreFix Sum: %1.10f\n",myrank,(t3-t2));
        // printArray(gArray,newsize,myrank);
    }
    MPI_Finalize();
    return 0;
}
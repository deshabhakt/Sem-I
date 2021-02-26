#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int dotProduct(int a[],int b[],int size)
{
    int result=0;
    for(int i=0;i<size;i++)
    {
        result+=a[i]*b[i];
    }
    return result;
}
void printArray(int arr[], int r, int myrank)
{
    printf("Vector at process %d is ",myrank);
    for (int i = 0; i <r; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main(int argc,char* argv[])
{
    int size,myrank,gresult;
    int N=atoi(argv[1]);  // tanking input from command line
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    int scattersize,newsize;
    if((N%size)==0)
    {
        scattersize=(N/size);
    }
    else
    {
        scattersize=(N/size)+1;
    }
    newsize=scattersize*size;
    int a[newsize];
    int b[newsize];
    if(myrank==0)
    {
        for(int i=0;i<newsize;i++)
        {
            if(i<N)
            {
            a[i]=rand()%(N*2);
            b[i]=rand()%(N*2);
            }
            else
            {
                a[i]=0;
                b[i]=0;
            }
        }
    }
    MPI_Barrier(MPI_COMM_WORLD);
    int c[scattersize];
    int d[scattersize];
    MPI_Scatter(&a,scattersize,MPI_INT,&c,scattersize,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(&b,scattersize,MPI_INT,&d,scattersize,MPI_INT,0,MPI_COMM_WORLD);
    double t1 = MPI_Wtime();
    int result=dotProduct(c,d,scattersize);
    double t2 = MPI_Wtime();
    printArray(c,scattersize,myrank);
    printArray(d,scattersize,myrank);
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
        printf("\nFinal dot product is %d.\n\n",gresult);
        printf("\nProcess: %d --> Time Required to Perform final reduce: %1.10f \n", myrank, (t3 - t2));
    }
    MPI_Finalize();
    return 0;    
}
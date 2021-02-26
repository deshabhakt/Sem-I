// Find Min and Max from an Array of size N 

#include<stdio.h>
#include<mpi.h>
#include <stdlib.h>
#include<time.h>
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
    int size,myrank,gmin,gmax;
    srand(time(0));
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int N=atoi(argv[1]);                //atoi -->Used to convert char to int && 
                                        // atoi(argv[1])-->used to take arraysize input from command line  
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
    if(myrank==0)
    {
        for(int i=0;i<newsize;i++)
        {
            if(i<N)
            {
                a[i]=rand()%(newsize*(2));
            }
            else
            {
                a[i]=0;
            }
            
        }
    }
    int localArray[scattersize];
    MPI_Scatter(&a,scattersize,MPI_INT,&localArray,scattersize,MPI_INT,0,MPI_COMM_WORLD);
    double t1=MPI_Wtime();
    int lmax=localArray[0];
    for(int i=0;i<scattersize;i++)
    {
        if(lmax<localArray[i])
        {
            lmax=localArray[i];
        }
    }
    printf("\n\nMAX of array at process %d is %d\n\n",myrank,lmax);
    double t2=MPI_Wtime();
    printf("Time required for process %d to calculate local MAX %1.10f \n",myrank,(t2-t1));
    printArray(localArray,scattersize,myrank);
    int lmin=localArray[0];
    for(int i=0;i<scattersize;i++)
    {

        if(lmin>localArray[i]&&localArray[i]!=0)
        {
            lmin=localArray[i];
        }
    }
    printf("\n\nMIN of array at process %d is %d\n\n",myrank,lmin);
    double t3=MPI_Wtime();
    printf("Time required for process %d to calculate local MIN %1.10f \n",myrank,(t3-t2));
    MPI_Reduce(&lmin,&gmin,1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);
    double t4=MPI_Wtime();
    MPI_Reduce(&lmax,&gmax,1,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);
    double t5=MPI_Wtime();
    if(myrank==0 && size>1)
    {
        printArray(a,newsize,myrank);
        printf("\n\nMIN of Entire array is %d\n\n",gmin);
        printf("\n\nMAX of Entire array is %d\n\n",gmax);
        printf("Time required for process %d to calculate global MIN %1.10f \n",myrank,(t4-t3));
        printf("Time required for process %d to calculate global MAX %1.10f \n",myrank,(t5-t4));
    }
    MPI_Finalize();
    return 0;
}
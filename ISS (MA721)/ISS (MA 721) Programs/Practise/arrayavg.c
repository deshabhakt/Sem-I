#include<mpi.h>

#include<stdio.h>

int main(int argc,char* argv[])

{

int size,myrank,avg,B[]={};

int A[6]={1,2,3,4,5,6};

MPI_Init(&argc,&argv);

MPI_Comm_size(MPI_COMM_WORLD,&size);

MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
int sc_size=6/size;
MPI_Scatter(&A,sc_size,MPI_INT,&B,sc_size,MPI_INT,0,MPI_COMM_WORLD);
int lsum=0;
for(int i=0;i<sc_size;i++)
{
    lsum+=B[i];
}
int gsum=0;
MPI_Reduce(&lsum,&gsum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

if(myrank==0)

{

    avg=(gsum/6);

    printf("Array element average is %d ",avg);

}   

MPI_Finalize();

return 0;

}
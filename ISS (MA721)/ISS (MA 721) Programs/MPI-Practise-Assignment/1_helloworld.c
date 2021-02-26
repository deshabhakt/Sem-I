//MPI Program - Hello World

#include <mpi.h>
#include<stdio.h>
int main(int argc,char*argv[])
{
    int rank,size;
    MPI_Init(&argc,&argv); //initializeMPIlibrary
    MPI_Comm_size(MPI_COMM_WORLD,&size);//getnumberofprocesses
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);//getmyprocessid//dosomething
    printf("Hello Worldfromrank%d\n",rank);
    if(rank==0)printf("MPIWorldsize=%dprocesses\n",size); 
    MPI_Finalize();//MPIfinish
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc, char* argv[])
{
int m_total, size, rank, n=12;
int A[n],B[n];
int UL=20,LL=1;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
int a[n/size], b[n/size];

if(rank==0)
{
for(int i=0; i<n; i++)
{
A[i]=(rand()%(UL-LL))+LL;
B[i]=(rand()%(UL-LL))+LL;
printf("A[%d]=%d , B[%d]=%d\n",i,A[i],i,B[i]);
}
}

MPI_Scatter(&A,n/size,MPI_INT,&a,n/size,MPI_INT,0,MPI_COMM_WORLD);
MPI_Scatter(&B,n/size,MPI_INT,&b,n/size,MPI_INT,0,MPI_COMM_WORLD);

MPI_Barrier(MPI_COMM_WORLD);
int l_total=0;
for(int i=0;i<(n/size);i++)
{

l_total += (a[i]*b[i]);
printf("a[%d]=%d , b[%d]=%d // for process %d\n",i,a[i],i,b[i],rank);
}

MPI_Reduce(&l_total,&m_total,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

if(rank==0)
{
printf("\nResult:(A.B)= %d",m_total);
}

MPI_Finalize();
return 0;
}

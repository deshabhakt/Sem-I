#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define FROM_MASTER 1          /* setting a message type */
#define FROM_WORKER 2          /* setting a message type */

int main (int argc, char *argv[])
{
int N=atoi(argv[1]);     /* Taking input from command line*/
int	size,              /* number of processes in partition */
	myrank,                /* a task identifier */
	numworkers,            /* number of worker processes */
	source,                /* task id of message source */
	dest,                  /* task id of message destination */
	mtype,                 /* message type */
	rows,                  /* rows of matrix A sent to each worker */
	averow, extra, offset, /* used to determine rows sent to each worker */
	i, j, k, rc;           /* misc */
double	a[N][32],           /* matrix A to be multiplied */
	b[32][N],           /* matrix B to be multiplied */
	c[N][N];           /* result matrix C */
MPI_Status status;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if (size < 2 ) {
  printf("Need at least two MPI processes. Quitting...\n");
  MPI_Abort(MPI_COMM_WORLD,rc);
  exit(1);
  }
numworkers = size-1;

/**************************** master task ************************************/
   if (myrank == 0)
   {
      printf("Initializing arrays...\n");
      for (i=0; i<N; i++)
         for (j=0; j<32; j++)
            a[i][j]= i+j;
      for (i=0; i<32; i++)
         for (j=0; j<N; j++)
            b[i][j]= i*j;

      /* Send matrix data to the worker processes */
      averow = N/numworkers;
      extra = N%numworkers;
      offset = 0;
      mtype = FROM_MASTER;
      for (dest=1; dest<=numworkers; dest++)
      {
         rows = (dest <= extra) ? averow+1 : averow;   	
         MPI_Send(&offset, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
         MPI_Send(&rows, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
         MPI_Send(&a[offset][0], rows*32, MPI_DOUBLE, dest, mtype,
                   MPI_COMM_WORLD);
         MPI_Send(&b, 32*N, MPI_DOUBLE, dest, mtype, MPI_COMM_WORLD);
         offset = offset + rows;
      }

      /* Receive results from worker processes */
      mtype = FROM_WORKER;
      for (i=1; i<=numworkers; i++)
      {
         source = i;
         MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
         MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
         MPI_Recv(&c[offset][0], rows*N, MPI_DOUBLE, source, mtype, 
                  MPI_COMM_WORLD, &status);
         printf("Received results from task %d\n",source);
      }

      /* Print results */
      printf("******************************************************\n");
      printf("Result Matrix:\n");
      for (i=0; i<N; i++)
      {
         printf("\n"); 
         for (j=0; j<N; j++) 
            printf("%8.2f   ", c[i][j]);
      }
      printf("\n******************************************************\n");
      printf ("Done.\n");
   }


/**************************** worker task ************************************/
   if (myrank > 0)
   {
      mtype = FROM_MASTER;
      double t1 = MPI_Wtime();
      MPI_Recv(&offset, 1, MPI_INT, 0, mtype, MPI_COMM_WORLD, &status);
      MPI_Recv(&rows, 1, MPI_INT, 0, mtype, MPI_COMM_WORLD, &status);
      MPI_Recv(&a, rows*32, MPI_DOUBLE, 0, mtype, MPI_COMM_WORLD, &status);
      MPI_Recv(&b, 32*N, MPI_DOUBLE, 0, mtype, MPI_COMM_WORLD, &status);
      for (k=0; k<N; k++)
         for (i=0; i<rows; i++)
         {
            c[i][k] = 0.0;
            for (j=0; j<32; j++)
               c[i][k] = c[i][k] + a[i][j] * b[j][k];
         }
      double t2 = MPI_Wtime();
      printf("\nTotal Run Time: %1.10f \n",myrank,(t2-t1));
      mtype = FROM_WORKER;
      MPI_Send(&offset, 1, MPI_INT, 0, mtype, MPI_COMM_WORLD);
      MPI_Send(&rows, 1, MPI_INT, 0, mtype, MPI_COMM_WORLD);
      MPI_Send(&c, rows*N, MPI_DOUBLE, 0, mtype, MPI_COMM_WORLD);
   }
   MPI_Finalize();
}
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stddef.h>
#include "mpi.h"
int main(int argc, char *argv[])
{
   int i, j, k, rc, myrank, size, tag = 99;
   int sum = 0;
   int N=atoi(argv[1]);     /* Taking input from command line*/
   
   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &size);
   MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
   int from = myrank * (N*32)/size;
   int to = (myrank+1) * (N*32)/size;
   double aa[N * 32 / size], cc[N *N];
   double a[N][32],b[32][N];
   double c[N][N];
   if (size < 2)
   {
      printf("Need at least two MPI processes. Quitting...\n");
      MPI_Abort(MPI_COMM_WORLD, rc);
      exit(1);
   }
   double t1 = MPI_Wtime();
   if(myrank==0)
   {
     
   printf("Initializing arrays...\n");
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < 32; j++)
      {
         a[i][j] = i + j;
      }
   }
   for (int i = 0; i < 32; i++)
   {
      for (int j = 0; j < N; j++)
      {
         b[i][j] = i - j;
      }
   }
   }
   //scatter rows of first matrix to different processes
   MPI_Scatter(&a, N * 32/size, MPI_INT, &aa, N * 32/size, MPI_INT, 0, MPI_COMM_WORLD);

   //broadcast second matrix to all processes
   MPI_Bcast(&b, 32 * N, MPI_INT, 0, MPI_COMM_WORLD);

   MPI_Barrier(MPI_COMM_WORLD);

   //performing vector multiplication by all processes
   for (i = 0; i < N; i++)
   {
      for (j = 0; j < 32; j++)
      {
         sum = sum + aa[j] * b[j][i]; 
      }
      cc[i] = sum;
      sum = 0.00;
   }
   for (i = 0; i < N; i++) 	// for each row of A
	{
      for (j = 0; j < N; j++)  	// for each column of B
		{
         c[i][j] = 0;
			for (k = 0; k < 32; k++)
			{
            c[i][j] = c[i][j] + a[i][k] * b[k][j];
         }
      }
   }
   MPI_Gather(cc, N * N/size, MPI_INT, c, N * N, MPI_INT, 0, MPI_COMM_WORLD);
   double t2 = MPI_Wtime();
   printf("\nTotal Run Time of process %d : %1.10f \n", myrank, (t2 - t1));
   MPI_Barrier(MPI_COMM_WORLD);
   MPI_Finalize();
   if (myrank == 0)
   {
      printf("******************************************************\n");
      printf("Result Matrix:\n");
      for (i = 0; i < N; i++)
      {
         printf("\n");
         for (j = 0; j < N; j++)
            printf("%1.2f   ", c[i][j]);
      }
      printf("\n******************************************************\n");
      printf("Done.\n");
   }
   return 0;
}

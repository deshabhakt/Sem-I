#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define FROM_MASTER 1 //tag for messages sent from master to slaves
#define FROM_WORKER 4 //tag for messages sent from slaves to master

int main(int argc, char *argv[])
{
   int N = atoi(argv[1]); /* Taking input from command line*/
   int myrank, size, i, j, k, rc, low_bound, upper_bound, portion;
double a[N][32], b[32][N], c[N][N];
   double t1, t2;
   MPI_Status status;                      // store status of a MPI_Recv
   MPI_Request request;                    //capture request of a MPI_Isend
   MPI_Init(&argc, &argv);                 //initialize MPI operations
   MPI_Comm_rank(MPI_COMM_WORLD, &myrank); //get the myrank
   MPI_Comm_size(MPI_COMM_WORLD, &size);   //get number of processes
   if (size < 2)
   {
      printf("Need at least two MPI processes. Quitting...\n");
      MPI_Abort(MPI_COMM_WORLD, rc);
      exit(1);
   }
   /* master initializes work*/
   if (myrank == 0)
   {
      printf("Initializing arrays...\n");
      for (i = 0; i < N; i++)
      {
         for (j = 0; j < 32; j++)
         {
            a[i][j] = i + j;
         }
      }
      for (i = 0; i < 32; i++)
      {
         for (j = 0; j < N; j++)
         {
            b[i][j] = i - j;
         }
      }
      t1 = MPI_Wtime();
      for (i = 1; i < size; i++)
      {
         portion = (N / (size - 1));
         low_bound = (i - 1) * portion;
         if (((i + 1) == size) && ((N % (size - 1)) != 0))
         {
            upper_bound = N;
         }
         else
         {
            upper_bound = low_bound + portion;
         }
         MPI_Isend(&low_bound, 1, MPI_INT, i, FROM_MASTER, MPI_COMM_WORLD, &request);
         MPI_Isend(&upper_bound, 1, MPI_INT, i, FROM_MASTER + 1, MPI_COMM_WORLD, &request);
         MPI_Isend(&a[low_bound][0], (upper_bound - low_bound) * 32, MPI_DOUBLE, i, FROM_MASTER + 2, MPI_COMM_WORLD, &request);
      }
   }
   MPI_Bcast(&b, 32 * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

   /* work done by slaves*/
   if (myrank > 0)
   {
      MPI_Recv(&low_bound, 1, MPI_INT, 0, FROM_MASTER, MPI_COMM_WORLD, &status);
      MPI_Recv(&upper_bound, 1, MPI_INT, 0, FROM_MASTER + 1, MPI_COMM_WORLD, &status);
      MPI_Recv(&a[low_bound][0], (upper_bound - low_bound) * 32, MPI_DOUBLE, 0, FROM_MASTER + 2, MPI_COMM_WORLD, &status);
      for (i = low_bound; i < upper_bound; i++)
      {
         for (j = 0; j < N; j++)
         {
            for (k = 0; k < 32; k++)
            {
               c[i][j] += (a[i][k] * b[k][j]);
            }
         }
      }

      MPI_Isend(&low_bound, 1, MPI_INT, 0, FROM_WORKER, MPI_COMM_WORLD, &request);
      MPI_Isend(&upper_bound, 1, MPI_INT, 0, FROM_WORKER + 1, MPI_COMM_WORLD, &request);
      MPI_Isend(&c[low_bound][0], (upper_bound - low_bound) * N, MPI_DOUBLE, 0, FROM_WORKER + 2, MPI_COMM_WORLD, &request);
   }

   /* master gathers processed work*/
   if (myrank == 0)
   {
      for (i = 1; i < size; i++)
      {
         MPI_Recv(&low_bound, 1, MPI_INT, i, FROM_WORKER, MPI_COMM_WORLD, &status);
         MPI_Recv(&upper_bound, 1, MPI_INT, i, FROM_WORKER + 1, MPI_COMM_WORLD, &status);
         MPI_Recv(&c[low_bound][0], (upper_bound - low_bound) * N, MPI_DOUBLE, i, FROM_WORKER + 2, MPI_COMM_WORLD, &status);
      }
      t2 = MPI_Wtime();
      printf("\nTotal Run Time: %1.10f \n", myrank, (t2 - t1));
      /* Print results */
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
   MPI_Finalize();
   return 0;
}

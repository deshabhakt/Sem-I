#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

double funX(double x)
{
   return (4 / (1 + (x * x)));
}

double funY(double y1, double y2, double h)
{
   return (0.5 * h * (y1 + y2));
}

int main(int argc, char *argv[])
{
   int myrank, size;
   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &size);
   MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
   int N=atoi(argv[1]);                            // tanking input from command line
   double lsum = 0;
   double I;
   MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
   MPI_Barrier(MPI_COMM_WORLD);
   int scattersize = (N / size);
   double X[N], x[scattersize], y[scattersize];
   double h = (1.00 / N);

   if (myrank == 0)
   {
      for (int i = 0; i < N; i++)
      {
         X[i] = (i * h);
      }
   }
   MPI_Scatter(&X, scattersize, MPI_DOUBLE, &x, scattersize, MPI_DOUBLE, 0, MPI_COMM_WORLD);
   double t1=MPI_Wtime();
   for (int i = 0; i < scattersize; i++)
   {
      y[i] = funX(x[i]);
   }

   for (int i = 1; i < scattersize; i++)
   {
      lsum += funY(y[i - 1], y[i], h);
   }
   double t2 = MPI_Wtime();
   printf("\nProcess: %d --> Time Required to find it's part of Pi : %1.10f \n", myrank, (t2 - t1));
   MPI_Reduce(&lsum, &I, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
   double t3 = MPI_Wtime();
   MPI_Barrier(MPI_COMM_WORLD);
   if (myrank == 0)
   {
      printf("\nProcess: %d --> Time Required to Perform final Reduce : %1.10f \n", myrank, (t3 - t2));
      printf("Value of 'pi' for %d intervals is : \n%1.25f\n", N, I);
   }
   MPI_Finalize();
   return 0;
}

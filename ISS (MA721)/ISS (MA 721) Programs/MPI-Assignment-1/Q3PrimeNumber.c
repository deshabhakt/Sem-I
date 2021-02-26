#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void printArray(int arr[], int r, int myrank)
{
    printf("Array at process %d is ", myrank);
    for (int i = 0; i < r; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    int myrank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    int N = atoi(argv[1]) - 1; //Taking input from Command line
    int scattersize;
    if ((N - 1) % size == 0)
    {
        scattersize = (N - 1) / size;
    }
    else
    {
        scattersize = ((N - 1) / size) + 1;
    }
    int newsize = (size * scattersize);
    int a[newsize], b[scattersize], c[newsize];

    if (myrank == 0)
    {
        for (int i = 0; i < newsize; i++)
        {
            if (i < (N - 1))
            {
                a[i] = i + 2;
            }
            else
            {
                a[i] = 0;
            }
        }
    }
    MPI_Scatter(&a, scattersize, MPI_INT, &b, scattersize, MPI_INT, 0, MPI_COMM_WORLD);
    double t1 = MPI_Wtime();
    int i = 0, x;
    while (i < scattersize)
    {
        x = b[i] - 1;
        while (x >= 2)
        {
            if ((b[i] % x) == 0 && b[i] != 2)
            {
                b[i] = 0;
                break;
            }
            x--;
        }
        i++;
    }
    double t2 = MPI_Wtime();
    // printArray(temp,scattersize,myrank);
    printf("\nProcess: %d -> Time Required to find Prime's : %1.10f \n", myrank, (t2 - t1));
    MPI_Gather(&b, scattersize, MPI_INT, &c, scattersize, MPI_INT, 0, MPI_COMM_WORLD);

    if (myrank == 0)
    {
        printf("\nThe prime numbers are as follows:\n");

        for (int i = 0; i < newsize; i++)
        {
            if (c[i] != 0
            {
                printf("%d ", c[i]);
            }
        }
    }

    MPI_Finalize();
    return 0;
}
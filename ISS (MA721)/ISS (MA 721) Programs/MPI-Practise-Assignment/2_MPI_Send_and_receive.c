#include <mpi.h>

#include <stdio.h>

int main(int argc, char *argv[])

{

    int size, myrank, x, i;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    if (myrank == 0)
    {
        x = 10;
        MPI_Send(&x, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
    }

    else if (myrank == 1)

    {

        printf("Value of x is : %d\n", x);
        MPI_Recv(&x, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        printf("Process %d of %d, Value of x is %d\n", myrank, size, x);
        printf("Source %d Tag %d \n", status.MPI_SOURCE, status.MPI_TAG);
    }
    MPI_Finalize();

    return 0;
}

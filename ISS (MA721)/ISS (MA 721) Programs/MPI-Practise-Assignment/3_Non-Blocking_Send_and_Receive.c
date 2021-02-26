#include <mpi.h>

#include <stdio.h>

int main(int argc, char *argv[])

{

    int size, myrank, x, i;
    MPI_Status status;
    MPI_Request request;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    if (myrank == 0)
    {

        x = 10;

        MPI_Isend(&x, 1, MPI_INT, 1, 20, MPI_COMM_WORLD, &request); // Tag is different at receiver.

        for (i = 0; i < 5; i++)
            MPI_Send(&i, 1, MPI_INT, 1, i, MPI_COMM_WORLD);
    }

    else if (myrank == 1)

    {

        printf("Value of x is : %d\n", x);
        MPI_Irecv(&x, 1, MPI_INT, 0, 25, MPI_COMM_WORLD, &request);
        printf("Process %d of %d, Value of x is %d\n", myrank, size, x);
        printf("Source %d Tag %d \n", status.MPI_SOURCE, status.MPI_TAG);
        for (i = 0; i < 5; i++)
        {

            MPI_Recv(&i, 1, MPI_INT, 0, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // no status information

            printf("Received i : %d\n", i);
        }
    }
    MPI_Finalize();
    return 0;
}

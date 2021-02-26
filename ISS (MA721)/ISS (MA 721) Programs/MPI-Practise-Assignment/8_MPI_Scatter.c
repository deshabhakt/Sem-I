// 8. Demonstration of MPI_Scatter()


// • Note that the program is hard coded to work with 4 processes receiving two chunks from the array.

// • You may change according to what you want to explore.

#include <mpi.h>

#include <stdio.h>

    int main(int argc, char *argv[])

{

    int size, myrank, x[8], y[2], i;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    if (myrank == 0)
    {
        printf("Enter 8 values into array x:\n");
        for (i = 0; i < 8; i++)

            scanf("%d", &x[i]);
    }
    MPI_Scatter(&x, 8/size, MPI_INT, &y, 8/size, MPI_INT, 0, MPI_COMM_WORLD);
    for (i = 0; i < (8/size); i++)
        printf("\nValue of y in process %d : %d\n", myrank, y[i]);
    MPI_Finalize();
    return 0;
}

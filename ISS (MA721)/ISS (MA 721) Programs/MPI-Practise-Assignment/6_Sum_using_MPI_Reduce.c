

#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])

{

    int size, myrank, i, x, y;
    x = atoi(argv[1]);

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    int sc_size=0,newsize=0;
    
        if (x % size == 0)
        {
            sc_size = (x / size);
        }
        else
        {
            sc_size = (x / size) + 1;
        }
        newsize=size*sc_size;
        int ar[newsize];
        for(int i=0;i<newsize;i++)
        {
            if(i<x)
                ar[i]=i+1;
            else
                ar[i]=0;
        }
    int sc_ar[sc_size];
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Scatter(&ar, newsize / size, MPI_INT, &sc_ar, sc_size, MPI_INT, 0, MPI_COMM_WORLD);
    int lsum = 0;
    for (int i = 0; i < sc_size; i++)
    {
        lsum += sc_ar[i];
    }
    MPI_Reduce(&lsum, &y, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (myrank == 0)

    {

        printf("Value of y after reduce : %d\n", y);
    }
    MPI_Finalize();
    return 0;
}
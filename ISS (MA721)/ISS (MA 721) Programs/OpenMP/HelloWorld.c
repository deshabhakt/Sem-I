#include<stdio.h>
#include<omp.h>
int main(int *argc,char* argv[])
{
    #pragma omp parallel
    {
        int numt= omp_get_num_threads();
        int tid = omp_get_thread_num();
        printf("Hello World from %d of %d\n",tid,numt);
    }
    return 0;
}


//export OMP_NUM_THREADS = 4  --->command used to specify number of threads (which here are 4)
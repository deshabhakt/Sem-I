#include <omp.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x = 0;
    #pragma omp parallel num_threads(50) shared(x)
    { 
        int tid = omp_get_thread_num();
        x = x + 1;
        printf("Thread [%d] value of x is %d \n", tid, x);
    }
}
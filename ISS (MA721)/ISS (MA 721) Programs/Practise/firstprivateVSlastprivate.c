#include <stdio.h>
#include <omp.h>

int main (void)
{
    int i;
    #pragma omp parallel private(i)
    {
        i = i + omp_get_thread_num();
        printf("thread %d: i = %d\n", omp_get_thread_num(), i);
    }

    printf("i = %d\n", i);

    return 0;
}

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define N 4
int main()
{
    int a[N],i;
    #pragma omp parallel num_threads(N) shared(a) private(i)
    {
        i=omp_get_thread_num();
        a[i] = i;
        #pragma omp master
            printf("YOU SHOULD ONLY SEE THIS ONCE\n");
        printf("a[%d]=%d\n",i,a[i]);
    }

    printf("\nTHIS IS SERIAL PART\n");
    for(int i=0;i<N;i++)
    {
        printf("a[%d]=%d", i, a[i]);
        if(i<N-1)
            printf(" --> ");
    }
    printf("\n");
}

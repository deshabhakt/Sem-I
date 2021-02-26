#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#define N 1000
int main()
{
    long a[N][N], mx = -1, lmx = -1, i, j;
    for (j = 0; j < N; j++)
        for (i = 0; i < N; i++)
            a[i][j] = 1 + ((int)(rand() % (N *(i+1))));
    #pragma omp parallel private(i) firstprivate(lmx) num_threads(40)
    {
        int tid=omp_get_thread_num();
        #pragma omp for
        for (j = 0; j < N; j++)
            for (i = 0; i < N; i++){
                lmx = (lmx > a[i][j]) ? lmx : a[i][j];
            }
    // #pragma omp critical
        mx = (mx > lmx) ? mx : lmx;
            printf("tid=%d\t: max:%d\n",tid,lmx);

    }
    printf("max value of a is %d\n", mx);
}

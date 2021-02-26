#include<stdio.h>
#include<omp.h>
int main()
{
    int nthreads,tid;
    int x;
    scanf("%d",&x);
    #pragma omp parallel private(tid) num_threads(x) 
    {
        tid=omp_get_thread_num();
        printf("Hello world from thread=%d\n",tid);
        if(tid==0)
        {
            printf("Number of threads=%d\n",x);
        }       
    }
}
#include <stdio.h>
#include <omp.h>
/*copyin(x) copies initialized value of x (from outside the pragma directive) in all threads  (inside the pragma directive)*/

/*initializing x globally works same 
as (using copyin(x) clause and initializing x in main function)*/

int tid, x=10;             //here x is not initialized                                         

#pragma omp threadprivate(x,tid)           // creates copy of variables for each thread
void main()
{
    // x = 10;             // x initialized here 
    #pragma omp parallel num_threads(4) copyin(x)  // to use copyin(x)--> x must be threadprivate
    {
        tid = omp_get_thread_num();
        #pragma omp master          // updates only master (i.e 0) thread
        {
            printf("Parallel Region 1 \n");
            x = x + 1;
        }
        #pragma omp barrier         //all threads wait here until remaining threads reach here
        if (tid == 1)
            x = x + 2;
        printf("Thread % d Value of x is %d\n", tid, x);
    }
    #pragma omp parallel num_threads(4)
    {
        #pragma omp master
        {
        printf("Parallel Region 2 \n");         //executed only once because of #pragma omp master command
        }
        #pragma omp barrier
        printf("Thread %d Value of x is %d\n", tid, x);
    }
    printf("Value of x in Main Region is %d\n", x);
}
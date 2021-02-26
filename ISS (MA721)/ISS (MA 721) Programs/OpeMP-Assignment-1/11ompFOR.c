#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
// #define CHUNKSIZE 5
// #define N 100
// int main(int argc, char *argv[])
// {
//     int nthreads, tid, i, chunk;
//     float a[N], b[N], c[N];
//     for (i = 0; i < N; i++)
//         a[i] = b[i] = i * 1.0;
//     chunk = CHUNKSIZE;
//     #pragma omp parallel shared(a, b, c, nthreads, chunk) private(i, tid) num_threads(5)
//     {
//         tid = omp_get_thread_num();
//         if (tid == 0)
//         {
//             nthreads = omp_get_num_threads();
//             printf("Number of threads = %d\n", nthreads);
//         }
//         printf("Thread %d starting...\n", tid);
//         #pragma omp for schedule(guided, chunk)
//         for (i = 0; i < N; i++)
//         {
//             c[i] = a[i] + b[i];
//             printf("Thread %d:c[% d] = % f\n", tid, i, c[i]);
//         }
//     }
// } 
// void main() {

// int x=0;

// #pragma omp parallel num_threads(8) reduction(+:x)

// {

// int id=omp_get_thread_num();

// int threads=omp_get_num_threads();

// x=x+10;

// }

// printf("x=%d",x);

// }
void main(){

int a[10][10], mx=-1, lmx=-1, i, j;

for (j=0; j<10; j++)

for (i=0; i<10; i++)

 {a[i][j]=i+j;

printf("%d ",a[i][j]);

}

#pragma omp parallel private(i) firstprivate(lmx) num_threads(10)

{

#pragma omp for

for (j=0; j<10; j++)

for (i=0; i<10; i++)

lmx = (lmx > a[i][j]) ? lmx : a[i][j];

mx = (mx > lmx) ? mx : lmx;

}

printf("max value of a is %d\n",mx);

}
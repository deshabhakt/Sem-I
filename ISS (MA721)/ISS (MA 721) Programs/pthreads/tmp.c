    //     #include<stdio.h>

    //    #include<pthread.h> 

    //    int a;  

    //    void *fun_t(void *arg);

    //    void *fun_t(void *arg)

    //    {       

    //        printf("%d\n",a);

    //        pthread_exit("Bye");

    //    }

    //    int main()

    //    {

    //        pthread_t pt;

    //        void *res_t;         

    //        a = 10;

    //        if(pthread_create(&pt,NULL,fun_t,NULL) != 0)

    //            perror("pthread_create");

    //        if(pthread_join(pt,&res_t) != 0)

    //            perror("pthread_join");

    //        return 0;

    //    }

// #include <omp.h>
// #include <stdio.h>

//     int main()
//     {
//         int i, a[4];
//         #pragma omp parallel private(i)
//         {
//             int tid = omp_get_thread_num();
//             // #pragma omp for
//             for (int i = 0; i < 4; i++)
//             {
//                 a[i] = i;
//                  printf("tid:%d-->a[%d]=%d\n", tid, i, a[i]);
//             }
//             // #pragma omp for
//             // for (int i = 0; i < 4; i++)
//             // {
//             //     printf("tid:%d-->a[%d]=%d\n", tid, i, a[i]);
//             // }
//         }
//     }

#include <omp.h>
#include <stdio.h>

int x;
int main()
    {
        x=10;
        printf("%d",x);
    }

// #include<omp.h>

// #include<stdio.h>
// void main() {

// int x=0;

// #pragma omp parallel num_threads(8) reduction(+:x)

// {

// int id=omp_get_thread_num();

// int threads=omp_get_num_threads();

// x=x+2;

// }

// printf("x=%d",x);

// }
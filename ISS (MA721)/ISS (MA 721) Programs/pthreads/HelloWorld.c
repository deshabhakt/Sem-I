#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int thread_count;
void* Hello(void* rank)
{
    long my_rank = (long) rank;
    int x=thread_count;
    if(my_rank%2==0 && my_rank<thread_count-1)
    {
    printf("\n%ld:Hello thread %ld,I am thread %ld of %d and I have %ld\n",my_rank,my_rank+1,my_rank,thread_count,my_rank+1);
    x++;
    }
    else if(my_rank%2!=0 && my_rank<thread_count-1)
    {
        printf("\n%ld:Hey thread %ld, I am thread %ld of %d and i have %ld\n",my_rank,my_rank-1,my_rank,thread_count,my_rank+1);
        x++;
    }
    else if(x==thread_count && thread_count%2!=0)
    {
        printf("\n%ld:I am alone :( but i have %d :)\n",my_rank,x);
    }
    
    pthread_exit(0);
}
int main(int argc, char* argv[])
{
    long thread;
    pthread_t* thread_handles;
    thread_count=strtol(argv[1],NULL,10);
    thread_handles = malloc (thread_count*sizeof(pthread_t));
    for(thread=0;thread<thread_count;thread++)
    {
        pthread_create(&thread_handles[thread],NULL,Hello, (void*) thread);
    }
    free(thread_handles);
    pthread_exit(NULL);
    printf("\n");
    return 0;
}
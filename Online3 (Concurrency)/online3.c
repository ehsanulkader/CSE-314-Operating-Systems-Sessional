#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <wait.h>
#include <pthread.h>
#include "zemaphore.h"

#define NUM_THREADS 3

zem_t zem[NUM_THREADS];

void *RRD(void *data)
{
    int thread_id = *((int *)data);
    while(1) {
        zem_down(&zem[thread_id]);
        printf("RRD %d\n", thread_id);
        zem_up(&zem[(thread_id+1)%NUM_THREADS]);
    }
  return 0;
}

void *BB(void *data)
{
    int thread_id = *((int *)data);
    while(1) {
        zem_down(&zem[thread_id]);
        printf("BB %d\n", thread_id);
        zem_up(&zem[(thread_id+1)%NUM_THREADS]);
    }
  return 0;
}

void *MTH(void *data)
{
    int thread_id = *((int *)data);
    while(1) {
      zem_down(&zem[thread_id]);
      printf("MTH %d\n", thread_id);
      zem_up(&zem[(thread_id+1)%NUM_THREADS]);
    }
    return 0;
}

int main(int argc, char *argv[]) {

    pthread_t mythreads[NUM_THREADS];
    int mythread_id[NUM_THREADS];
    zem_init(&zem[0], 1);
    for (int i = 1; i < NUM_THREADS; i++) {
        zem_init(&zem[i], 0);
    }
  
    for(int i =0; i < NUM_THREADS; i++) {
      mythread_id[i] = i;
    }
    pthread_create(&mythreads[0], NULL, RRD, (void *)&mythread_id[0]);
    pthread_create(&mythreads[1], NULL, BB, (void *)&mythread_id[1]);
    pthread_create(&mythreads[2], NULL, MTH, (void *)&mythread_id[2]);
    for(int i =0; i < NUM_THREADS; i++) {
      pthread_join(mythreads[i], NULL);
    }
  
    return 0;
}

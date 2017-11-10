#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include "threads.h"
#define NUM_THREADS    10

int unsigned total;
sem_t sem1;
sem_t forks[NUM_THREADS];
sem_t chairs;

void thinking(int n){
  sleep(rand()%n);
}
void eating(int n){
  sleep(rand()%n);
}

void *lifeStyle(void *threadid){
  long tid;
  tid = (long)threadid;
  while(1){
    thinking(3);
    printf("I am phil %lu, I am hungry\n", tid);

    sem_wait(&forks[tid]);
    sem_wait(&forks[(tid+1)%NUM_THREADS]);
    sem_wait(&chairs);


    eating(4);
    sem_post(&forks[tid]);
    sem_post(&forks[(tid+1)%NUM_THREADS]);
    sem_post(&chairs);
    printf("I am phil %lu, I am thinking\n", tid);
  }

}

void *add100(void *threadid){

   long tid;

   tid = (long)threadid;

   unsigned int localTotal;
   printf("Adding 100 #%ld!\n", tid);
   sem_wait(&sem1);
   localTotal = total;
   localTotal += 100;
   sleep(tid%5);
   total = localTotal;
   sem_post(&sem1);

   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   //total = 0;
   //sem_init(&sem1, 1, 1);
   for(t = 0; t < NUM_THREADS; t++){
     sem_init(&forks[t],0,1);
   }
   sem_init(&chairs,0,NUM_THREADS/2);
   for(t=0; t<NUM_THREADS; t++){
      printf("In main: creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, lifeStyle, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   for(t = 0; t < NUM_THREADS; t++){
     pthread_join(threads[t], NULL);
   }

   //printf("Final total =%d \n", total);
   /* Last thing that main() should do */
}

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "threads.h"
#define NUM_THREADS     50

int unsigned total;

void *add100(void *threadid)

   long tid;

   tid = (long)threadid;
   printf("Adding 100 #%ld!\n", tid);
   total+=100;
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   total = 0;
   for(t=0; t<NUM_THREADS; t++){
      printf("In main: creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

|
   /* Last thing that main() should do */
   pthread_exit(NULL);
}

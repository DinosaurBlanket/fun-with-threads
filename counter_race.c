#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS     20

int counter;

void *increment(int amount) {
    counter += amount;
}

void *AddThings(void *threadid)
{
   long tid;
   int i;
   for (i = 0; i < 100000; i++) {
       increment(1);
   }
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld! I'm done.\n", tid);
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t=0; t<NUM_THREADS; t++){
      rc = pthread_create(&threads[t], NULL, AddThings, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(1);
      }
   }
   for (t = 0; t < NUM_THREADS; t++)
       pthread_join(threads[t], NULL);
   printf("Final value of counter is: %d\n", counter);

   /* Last thing that main() should do */
   pthread_exit(NULL);
}

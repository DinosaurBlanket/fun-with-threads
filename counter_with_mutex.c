#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "shared.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *AddThings(void *threadid) {
	for (int i = 0; i < num_increments; i++) {
		pthread_mutex_lock(&mutex);
		counter += 1;
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

int main (int argc, char **argv) {
	num_threads    = get_num_threads(argc, argv);
	num_increments = get_num_increments(argc, argv);
	print_params();
	
	pthread_t threads[num_threads];
	long t;
	for (t = 0; t < num_threads; t++) {
		int rc = pthread_create(&threads[t], NULL, AddThings, (void *)t);
		if (rc) {
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(1);
		}
	}
	for (t = 0; t < num_threads; t++)
		pthread_join(threads[t], NULL);
	print_result();
	pthread_exit(NULL);
}


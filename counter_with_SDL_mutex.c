#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "shared.h"

int counter;
SDL_mutex *mutex;

int AddThings(void *unused) {
	for (int i = 0; i < num_increments; i++) {
		SDL_LockMutex(mutex);
		counter += 1;
		SDL_UnlockMutex(mutex);
	}
	return 0;
}

int main (int argc, char **argv) {
	num_threads    = get_num_threads(argc, argv);
	num_increments = get_num_increments(argc, argv);
	print_params();
	
	mutex = SDL_CreateMutex();
	if (!mutex) {
		fprintf(stderr, "ERROR; Could not create mutex\n");
		exit(2);
	}
	
	SDL_Thread *threads[num_threads];
	long t;
	for (t = 0; t < num_threads; t++) {
		threads[t] = SDL_CreateThread(AddThings, "AddThings", (void *)NULL);
		if (!threads[t]) {
			fprintf(stderr, "ERROR; could not create thread %li\n", t);
			exit(1);
		}
	}
	for (t = 0; t < num_threads; t++)
		SDL_WaitThread(threads[t], NULL);
	SDL_DestroyMutex(mutex);
	print_result(counter);
}

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "shared.h"

SDL_atomic_t counter;

int AddThings(void *unused) {
	for (int i = 0; i < num_increments; i++) {
		SDL_AtomicIncRef(&counter);
	}
	return 0;
}

int main (int argc, char **argv) {
	num_threads    = get_num_threads(argc, argv);
	num_increments = get_num_increments(argc, argv);
	print_params();
	
	SDL_Thread *threads[num_threads];
	long t;
	for (t = 0; t < num_threads; t++) {
		threads[t] = SDL_CreateThread(AddThings, "AddThings", (void *)NULL);
		if (!threads[t]) {
			printf("ERROR; could not create thread %li\n", t);
			exit(1);
		}
	}
	for (t = 0; t < num_threads; t++)
		SDL_WaitThread(threads[t], NULL);
	print_result(SDL_AtomicGet(&counter));
}

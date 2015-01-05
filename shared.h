#define DEFAULT_NUM_THREADS    20
#define DEFAULT_NUM_INCREMENTS  1e6
#define MAX_THREAD_COUNT      120

int counter;
int num_threads;
int num_increments;

int get_num_threads(int argc, char **argv) {
	int nt = 0;
	if (argc > 1)
		nt = atoi(argv[1]);
	if (nt < 1 || nt > MAX_THREAD_COUNT)
		return DEFAULT_NUM_THREADS;
	return nt;
}

int get_num_increments(int argc, char **argv) {
	int ni = 0;
	if (argc > 2)
		ni = atoi(argv[2]);
	if (ni < 1)
		return DEFAULT_NUM_INCREMENTS;
	return ni;
}

void print_params(void) {
	printf("num_threads:    %i\nnum_increments: %i\n", num_threads, num_increments);
}

void print_result(void) {
	int expected = num_threads * num_increments;
	if (counter == expected) {
		printf("The result is correct: %i\n", counter);
		return;
	}
	printf("The result is NOT correct, wanted %i but got %i\n", expected, counter);
}

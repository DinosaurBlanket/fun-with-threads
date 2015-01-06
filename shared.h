#define DEFAULT_NUM_THREADS    20
#define DEFAULT_NUM_INCREMENTS  1e6
#define MAX_THREAD_COUNT      120

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

void print_result(int result) {
	int expected = num_threads * num_increments;
	if (result == expected) {
		fprintf(stderr, "PASS: %i\n", result);
		return;
	}
	printf("FAIL: %i\n", result);
}

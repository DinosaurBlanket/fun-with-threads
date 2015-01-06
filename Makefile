all:
	gcc -std=c99 -o bin/counter_race counter_race.c                   -lpthread
	gcc -std=c99 -o bin/counter_with_mutex counter_with_mutex.c       -lpthread
	gcc -std=c99 -o bin/counter_with_spinlock counter_with_spinlock.c -lpthread -D_POSIX_C_SOURCE=200112L
	gcc -std=c99 -o bin/counter_with_atomics counter_with_atomics.c   -lpthread -D_POSIX_C_SOURCE=200112L
	gcc -std=c99 -o bin/counter_with_SDL_mutex counter_with_SDL_mutex.c       `sdl2-config --cflags --libs`
	gcc -std=c99 -o bin/counter_with_SDL_atomics counter_with_SDL_atomics.c   `sdl2-config --cflags --libs`
	gcc -std=c99 -o bin/counter_with_SDL_spinlock counter_with_SDL_spinlock.c `sdl2-config --cflags --libs`
	rustc -O bin/rust_counter_mutex.rs
	rustc -O bin/rust_counter_atomics.rs

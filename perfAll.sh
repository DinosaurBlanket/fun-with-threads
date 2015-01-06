#!/bin/bash
runAndPrint() {
>&2 echo "counter_race"
>&2 perf stat bin/counter_race $1 $2
>&2 echo "\n\n\n\ncounter_with_mutex"
>&2 perf stat bin/counter_with_mutex $1 $2
>&2 echo "\n\n\n\ncounter_with_SDL_mutex"
>&2 perf stat bin/counter_with_SDL_mutex $1 $2
>&2 echo "\n\n\n\ncounter_with_spinlock"
>&2 perf stat bin/counter_with_spinlock $1 $2
>&2 echo "\n\n\n\ncounter_with_SDL_spinlock"
>&2 perf stat bin/counter_with_SDL_spinlock $1 $2
>&2 echo "\n\n\n\ncounter_with_atomics"
>&2 perf stat bin/counter_with_atomics $1 $2
>&2 echo "\n\n\n\ncounter_with_SDL_atomics"
>&2 perf stat bin/counter_with_SDL_atomics $1 $2
}
echo "writing to 'perfOut.txt'..."
runAndPrint $1 $2 2> perfOut.txt
exit 0

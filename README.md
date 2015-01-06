fun-with-threads
================


Examples of various ways (including one with a race condtion) to have several threads incrementing a single counter.
Mutexes, atomics, and spinlocks from both the pthread library and the SDL library are present, 
along with some standard Rust.

The script "perfAll.sh" will run all the examples and write perf statistics to the file "perfOut.txt".
This requires the "perf" tool to be installed.

The binaries and perfAll.sh both take two arguments, first is the number of threads to use, second is how many times to increment the counter.

Run "make" to build.
Some examples require SDL to be installed. 
The Rust examples obviously require Rust to be installed.

The original project was the subject of this blog post by Julia Evans: http://jvns.ca/blog/2014/12/14/fun-with-threads/

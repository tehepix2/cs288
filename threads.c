#include <stdio.h>
#include <pthread.h>

// compares between a single threaded vs multi threaded program.


void *computation(void *id);

int main() {
    /*
    long value1 = 1;
    long value2 = 2;
    
    computation(&value1);
    computation(&value2);
    */

    //pthread_create();  create new worker thread
    // parameters:
    // thread -> pointer to worker thread
    // attrs -> attributes to thread (just use NULL if none are specified)
    // thread function -> the function we want to execute in this thread
    // function arguments -> function arguments to thread function
    pthread_t thread1;
    pthread_t thread2;
    long value1 = 1;
    long value2 = 2;
    pthread_create(&thread1, NULL, computation, &value1);
    pthread_create(&thread2, NULL, computation, &value2); // program will finish here because it thinks its done.

    // now join threads
    // indicate the main thread to wait until worker threads are done.
    //pthread_join(pthread_t thread_name, void *retval);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}

void *computation(void *id) {
    long *myid = (long *)id;
    long sum=0;

    for (int i = 0; i < 1000000000; i++) {
        sum += *myid;
    }
}

/*
To write programs with multiple threads, use packages:
Pthread <- will focus on this (it means Posix Thread)
Open mp
*/
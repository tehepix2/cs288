#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
long *array, nthreads, s, length;

void *scalar(void *id) {
    long chunk = length / nthreads;
    long *myid = (long *)id;
    long start =  *myid * chunk;
    long end = start + chunk;

    if (*myid == nthreads - 1) {
        end = length;
    }
    for (int i = start; i < end; i++) {
        array[i] *= s;
    }

}
int main(int argc, char *argv[]) {
    nthreads = strtol(argv[1], NULL, 10);

    length = strtol(argv[2], NULL, 10);

    s = strtol(argv[3], NULL, 10);

    pthread_t *thread_array = malloc(nthreads * sizeof(pthread_t)); // array of threads!

    long *thread_ids = (long *)malloc(nthreads * sizeof(long));

    array = (long *)malloc(length * sizeof(long));

    for (int i = 0; i < length; i++) {
        array[i] = i;
    }

    for (int i = 0; i < nthreads; i++) {
        thread_ids[i] = i;
        pthread_create(&thread_array[i], NULL, scalar, &thread_ids[i]);
    }

    for (int i = 0; i < nthreads; i++) {
        pthread_join(thread_array[i], NULL);
    }

    // for (int i = 0; i < length; i++) {
    //     printf("%4ld\n", array[i]);
    // }
}
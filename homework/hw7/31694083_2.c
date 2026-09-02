#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t sem;


int num_threads;
int count[1000] = {0};
int *numbers;
int num_ints;
void *countsort(void *id) {
    long *myid = (long *)id;
    long chunk = num_ints / num_threads;
    long start = *myid * chunk;
    long end = start + chunk;
    int local_count[1000] = {0};
    for (int i = start; i < end; i++) {
        local_count[numbers[i]]++;
    }
    sem_wait(&sem);
    for (int i = 0; i < 1000; i++) {
        count[i]+=local_count[i];
    }
    sem_post(&sem);
}
int main(int argc, char *argv[]) {
    sem_init(&sem, 0, 1);
    char pathname[256];
    printf("Enter pathname: ");
    scanf("%s", pathname);

    FILE *file = fopen(pathname, "r+b");
    fseek(file, 0, SEEK_END);
    long size_in_bytes = ftell(file);
    fseek(file, 0, SEEK_SET);
    num_ints = size_in_bytes / sizeof(int);

    numbers = (int *)malloc(num_ints * sizeof(int));
    fread(numbers, sizeof(int), num_ints, file);

    num_threads = atoi(argv[1]);

    pthread_t *threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));

    long *threadids = (long *)malloc(num_threads * sizeof(long));

    for (int i = 0; i < num_threads; i++) {
        threadids[i] = i;
        pthread_create(&threads[i], NULL, countsort, &threadids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    int index = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < count[i]; j++) {
            numbers[index] = i;
            index++;
        }
    }
    fseek(file, 0, SEEK_SET);
    fwrite(numbers, sizeof(int), num_ints, file);


}
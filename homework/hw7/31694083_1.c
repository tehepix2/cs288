#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

double *A, *B, sum;
int num_threads;
int N;
pthread_mutex_t mutex;

void *dot(void *id) {
    long chunk = N / num_threads;
    long *myid = (long *)id;
    long start = *myid * chunk;
    long end = start + chunk;
    double local_sum = 0.0;
    if (*myid == num_threads - 1) {
        end = N;
    }
    for (int i = start; i < end; i++) {
        local_sum += A[i] * B[i];
    }

    pthread_mutex_lock(&mutex);
    sum += local_sum;
    pthread_mutex_unlock(&mutex);

}
int main(int argc, char *argv[]) {

    pthread_mutex_init(&mutex, NULL);
    sum = 0.0;
    printf("Enter length of arrays: ");
    scanf("%d", &N);
    A = (double *)malloc(N * sizeof(double));
    B = (double *)malloc(N * sizeof(double));

    for (int i = 0; i < N; i++) {
        printf("\nEnter value %d for first array: ", i + 1);
        scanf("%lf", &A[i]); 
    }
    for (int i = 0; i < N; i++) {
        printf("\nEnter value %d for second array: ", i + 1);
        scanf("%lf", &B[i]); 
    }
    num_threads = atoi(argv[1]);
    pthread_t *threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
    long *threadids = (long *)malloc(num_threads * sizeof(long));
    for (int i = 0; i < num_threads; i++) {
        threadids[i] = i;
        pthread_create(&threads[i], NULL, dot, &threadids[i]);

    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nDot product total: %lf", sum);
}
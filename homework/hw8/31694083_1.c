#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 100

int T; // number of threads
double A[N][N], B[N][N], C[N][N], C_serial[N][N];

void *multiply(void *arg) {
    int thread_id = *(int *)arg;

    int chunk = N / T;
    int start = thread_id * chunk;
    int end = start + chunk;
    if (thread_id == T - 1) {
        end = N;
    }

    for (int i = start; i < end; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // No mutex is needed because each thread writes only to its own
    // exclusive block of rows of C; no two threads ever access the
    // same C[i][j], so there is no shared data to protect.

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num_threads>\n", argv[0]);
        return 1;
    }

    T = atoi(argv[1]);
    pthread_t threads[T];
    int thread_ids[T];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i * j;
        }
    }

    for (int i = 0; i < T; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, multiply, &thread_ids[i]);
    }

    for (int i = 0; i < T; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C_serial[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                C_serial[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    int pass = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (C[i][j] != C_serial[i][j]) {
                pass = 0;
                break;
            }
        }
        if (!pass) break;
    }

    printf(pass ? "PASS\n" : "FAIL\n");

    return 0;
}
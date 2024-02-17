#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 8
#define M 16
#define NUM_THREADS 4

int a[N][M];
int x[M], b[N];

typedef struct
{
    unsigned int low;
    unsigned int high;
} thread_data;

thread_data thread_data_arr[NUM_THREADS];

void *calc_part(void *threadarg)
{
    thread_data *my = (thread_data *)threadarg;
    unsigned int i, j;
    for (i = my->low; i < my->high; i++)
    {
        b[i] = 0;
        for (j = 0; j < M; j++)
            b[i] += a[i][j] * x[j];
    }
    pthread_exit(NULL);
}

int main()
{
    unsigned int i, j;
    printf("Matrix:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            a[i][j] = (i + j) * (i + 1) * (j + 1);
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
    printf("Vector:\n");
    for (i = 0; i < M; i++)
    {
        x[i] = (M - i) * (M - i);
        printf("%6d", x[i]);
    }

    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    int rc;
    void *status;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    unsigned int t_part = N / NUM_THREADS;
    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_data_arr[i].low = i * t_part;
        thread_data_arr[i].high = thread_data_arr[i].low + t_part;
        rc = pthread_create(&threads[i], &attr, calc_part, (void *)&thread_data_arr[i]);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    pthread_attr_destroy(&attr);
    for (i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], &status);
        if (rc)
        {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    printf("\nParallel pthreads product:\n");
    for (i = 0; i < N; i++)
        printf("%12d", b[i]);
    printf("\n");

    return 0;
}

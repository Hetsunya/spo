#include <stdio.h>
#define N 8
#define M 16

int main()
{
    int a[N][M];
    int x[M], b[N];
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

    printf("\nSequential product:\n");
    for (i = 0; i < N; i++)
    {
        b[i] = 0;
        for (j = 0; j < M; j++)
            b[i] += a[i][j] * x[j];
        printf("%12d", b[i]);
    }
    printf("\n");

    return 0;
}

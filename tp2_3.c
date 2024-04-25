#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 7

int main()
{
    int i, j;
    double mt[N][M], *punt;
    punt = &mt[0][0];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            *(punt + i * M + j) = 1 + rand() % 100;
            printf(" %lf  ", *(punt + i * M + j));
        }
        printf("\n");
    }

    return 0;
}

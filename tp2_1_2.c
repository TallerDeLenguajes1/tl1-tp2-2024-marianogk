#include <stdio.h>
#include <stdlib.h>

#define N 20

int main()
{

    int i;
    double vt[N], *punt;

    punt = vt; 

    for (i = 0; i < N; i++)
    {
        *(punt+i) = 1 + rand() % 100;
        printf(" %f ", *(punt+i));
    }

    return 0;
}

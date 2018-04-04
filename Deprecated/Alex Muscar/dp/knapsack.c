#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int knapsack(int *weights, int *values, size_t count, size_t maxw)
{
    int v[100][100] = {};
    bool k[100][100] = {};

    for (int i = 0; i <= maxw; ++i)
    {
        v[0][i] = 0;
    }

    for (int i = 1; i <= count; ++i)
    {
        for (int j = 0; j <= maxw; j++)
        {
            if (weights[i] <= j && values[i] + v[i - 1][j - weights[i]] > v[i - 1][j])
            {
                v[i][j] = values[i] + v[i - 1][j - weights[i]];
                k[i][j] = true;
            }
            else
            {
                v[i][j] = v[i - 1][j];
                k[i][j] = false;
            }
        }
    }

    for (int i = 0; i <= count; ++i)
    {
        for (int j = 0; j <= maxw; j++)
        {
            printf("%2d ", k[i][j]);
        }
        printf("\n");
    }

    int j = maxw;
    for (int i = count; i > 0; --i)
    {
        if (k[i][j])
        {
            printf("item %d\n", i);
            j -= weights[i];
        }
    }

    return v[count][maxw];
}

int main(int argc, const char *argv[])
{
    int weights[] = { 0, 5, 4, 6, 3 };
    int values[] = { 0, 10, 40, 30, 50 };
    printf("%d\n", knapsack(weights, values, 4, 10));
    return 0;
}

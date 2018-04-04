#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int *a, int i, int j)
{
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

void printa(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int partition(int *a, int left, int right)
{
    int v = a[left];
    int i = left + 1;
    int j = right;

    while (true) {
        while (a[i] < v && i < right)
            i++;
        while (a[j] >= v && j > left)
            j--;
        if (i >= j)
            break;
        swap(a, i, j);
    }
    swap(a, left, j);
    return j;
}

void sort(int *a, int left, int right)
{
    if (left >= right)
        return;
    int v = partition(a, left, right);
    sort(a, left, v - 1);
    sort(a, v + 1, right);
}

int *gen_arr(size_t n)
{
    int *a = (int *) malloc(n * sizeof(int));
    while (n > 0)
        a[--n] = rand();
    return a;
}

int main(int argc, const char *argv[])
{
    // int a[100] = { 0 };
    int n = atoi(argv[1]);
    int *a = gen_arr(atoi(argv[1]));

    srand(time(NULL));

    // printf("n = ");
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     printf("a[%d] = ", i);
    //     scanf("%d", &a[i]);
    // }
    sort(a, 0, n - 1);
    // printa(a, n);
    return 0;
}

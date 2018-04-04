#include <stdio.h>
#include "dynarr.h"

int main(int argc, char *argv[])
{
    dynarr_t *arr = mk_dynarr(2);

    for (int i = 0; i < 1024; i++)
    {
        dynarr_push_back(arr, i);
    }

    for (int i = 0; i < 1024; i++)
    {
        printf("%d\n", dynarr_at(arr, i));
    }

    return 0;
}

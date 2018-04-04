#ifndef __DYNARR_H__
#define __DYNARR_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int *data;
    int capacity;
    int count;
} dynarr_t;

dynarr_t *mk_dynarr(int capacity);
void dynarr_push_back(dynarr_t *arr, int value);
int dynarr_at(dynarr_t *arr, int index);

#endif

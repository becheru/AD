#include "dynarr.h"

dynarr_t *mk_dynarr(int capacity)
{
    dynarr_t *arr = (dynarr_t *) malloc(sizeof(dynarr_t));
    arr->data = (int *) calloc(capacity, sizeof(int));
    arr->capacity = capacity;
    arr->count = 0;
    return arr;
}

void dynarr_push_back(dynarr_t *arr, int value)
{
    if (arr->count >= arr->capacity)
    {
        int new_capacity = arr->capacity * 2;
        int *new_data = (int *) realloc(arr->data, new_capacity * sizeof(int));
        if (new_data == NULL)
        {
            perror("can't grow array");
            exit(-1);
        }
        printf("array resize: %d -> %d\n", arr->capacity, new_capacity);
        arr->data = new_data;
        arr->capacity = new_capacity;
    }
    arr->data[arr->count] = value;
    arr->count++;
}

int dynarr_at(dynarr_t *arr, int index)
{
    assert(0 <= index && index < arr->count);
    return arr->data[index];
}

//
// Created by Alexandru Becheru on 12/03/2018.
//
#include <stdlib.h>
#include "vectors.h"

void merge_left_right(int *vector, int left, int middle, int right)
{
    int iterator_left, iterator_right, merge_iterator;
    int no_elements_left = middle - left + 1;
    int no_elements_right = right - middle;

    // Create temporary array
    int *vector_left = calloc(no_elements_left, sizeof(int));
    int *vector_right = calloc(no_elements_right, sizeof(int));

    // Copy the information from the initial vector to the left, respectively right vector
    for (iterator_left = 0; iterator_left < no_elements_left; iterator_left++)
        vector_left[iterator_left] = vector[left + iterator_left];
    for (iterator_right = 0; iterator_right < no_elements_right; iterator_right++)
        vector_right[iterator_right] = vector[middle + 1 + iterator_right];

    write_vector(vector_left, 0, no_elements_left);
    write_vector(vector_right, 0, no_elements_right);

    //merge vectors (interclasare)
    iterator_left = 0;
    iterator_right = 0;
    merge_iterator = left;
    while (iterator_left < no_elements_left && iterator_right < no_elements_right)
    {
        if (vector_left[iterator_left] <= vector_right[iterator_right])
        {
            vector[merge_iterator] = vector_left[iterator_left];
            iterator_left++;
        }
        else
        {
            vector[merge_iterator] = vector_right[iterator_right];
            iterator_right++;
        }
        merge_iterator++;
    }

    if (iterator_left < no_elements_left) {
        //Copy the remaining elements of left vector, if there are any
        while (iterator_left < no_elements_left) {
            vector[merge_iterator] = vector_left[iterator_left];
            iterator_left++;
            merge_iterator++;
        }
    }else{
        // Copy the remaining elements of the right vector, if there are any
        while (iterator_right < no_elements_right) {
            vector[merge_iterator] = vector_right[iterator_right];
            iterator_right++;
            merge_iterator++;
        }
    }
    //delete the temporary vectors from memory
    free(vector_left);
    free(vector_right);
}

void merge_sort(int *vector, int left, int right){
    int middle;

    if (left == right);
    else {
        middle = (left + right) / 2;
        merge_sort(vector, left, middle);
        merge_sort(vector, middle + 1, right);
        merge_left_right(vector, left, middle, right);
    }
}







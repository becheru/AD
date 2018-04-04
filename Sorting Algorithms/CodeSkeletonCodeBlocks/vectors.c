//
// Created by Alexandru Becheru on 12/03/2018.
//
#include <stdio.h>
#include "vectors.h"
#include <stdlib.h>


void read_vector(int *vector, int vector_length){
    int iterator = 0;

    for (iterator = 0;iterator < vector_length; iterator++){
        printf("\n vector[%d]=",iterator);
        scanf("%d",vector + iterator);
    }
}

void write_vector(int *vector, int start, int stop){
    int iterator = 0;

    printf("\n Vector: ");
    for (iterator = start; iterator < stop; iterator++){
        printf("%d ",*(vector + iterator));
    }
}

int find_min_position(int *vector, int vector_start, int vector_length){
    int iterator ;
    int min_position;
    int min = *(vector + vector_start);

    for (iterator = vector_start + 1; iterator < vector_length; iterator++) {
        if (*(vector+iterator) < min) {
            min = vector[iterator];
            min_position = iterator;
        }
    }

    return min_position;
}

int read_vector_length(){
    int aux = 0;

    printf("\n Give value= ");
    scanf("%d",&aux);

    return aux;
}

int *merge_vectors(int *vector_1, int vector_1_length, int *vector_2, int vector_2_length){
    //Interclasarea a doi vectori

    int vector_1_iterator = 0;
    int vector_2_iterator = 0;
    int vector_sorted_iterator = 0;
    int vector_sorted_length = vector_1_length + vector_2_length;
    int *vector_sorted = calloc(vector_sorted_length, sizeof(int));

    // we compare an element from the first vector with an element from the second vector
    // the element with the smallest value is added to the sorted/merged vector
    while ((vector_1_iterator < vector_1_length) && (vector_2_iterator < vector_2_length)) {
        if (*(vector_1 + vector_1_iterator) < *(vector_2 + vector_2_iterator)){
            *(vector_sorted + vector_sorted_iterator) = *(vector_1 + vector_1_iterator);
            vector_1_iterator++;
        }else{
            *(vector_sorted + vector_sorted_iterator) = *(vector_2 + vector_2_iterator);
            vector_2_iterator++;
        }
        vector_sorted_iterator++;
    }

    // if one of the vectors reaches the end
    // the elements from the other vectors get copied to the sorted/merged vector

    if (vector_1_iterator < vector_1_length){
        while (vector_1_iterator < vector_1_length){
            *(vector_sorted + vector_sorted_iterator) = *(vector_1 + vector_1_iterator);
            vector_1_iterator++;
            vector_sorted_iterator++;
        }
    }else{
        while (vector_2_iterator < vector_2_length){
            *(vector_sorted + vector_sorted_iterator) = *(vector_2 + vector_2_iterator);
            vector_2_iterator++;
            vector_sorted_iterator++;
        }
    }

    return vector_sorted;
}

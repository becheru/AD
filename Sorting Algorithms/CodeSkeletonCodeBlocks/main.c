#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"
#include "sort.h"
#include "basic.h"


int main(){
    int *vector_1;
    int vector_1_length;
    int min_position;

    int a = 5;
    int b = 6;

    printf("\n=========== Interchange of values through pointers ===========");
    printf("\nInitial value of a= %d",a);
    printf("\nInitial value of b= %d",b);
    interchange_values(&a, &b);
    printf("\nNew value of a= %d",a);
    printf("\nNew value of b= %d",b);

    printf("\n=========== Read and write vectors ===========");
    vector_1_length = read_vector_length();
    vector_1 = calloc(vector_1_length, sizeof(int));
    read_vector(vector_1, vector_1_length);
    write_vector(vector_1, 0, vector_1_length);

    printf("\n=========== Position of the minimum element in a vector ===========");
    min_position = find_min_position(vector_1, 0, vector_1_length);
    printf("\n The position of the  minimum element from the first vector is: %d", min_position);

    printf("\n=========== Selection Sort ===========");
    printf("\nThe unsorted values of vector 1 are:");
    write_vector(vector_1, 0, vector_1_length);
    selection_sort(vector_1,vector_1_length);
    printf("\nThe sorted values, selection sort method, of vector 1 is:");
    write_vector(vector_1, 0, vector_1_length);

    return 0;
}

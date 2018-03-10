#include <stdio.h>
#define G_MAX_VECTOR_LENGTH 1000

int g_vector_sorted[2*G_MAX_VECTOR_LENGTH];
int g_vector_sorted_length = 0;
int g_vector_1[G_MAX_VECTOR_LENGTH];
int g_vector_1_length = 0;
int g_vector_2[G_MAX_VECTOR_LENGTH];
int g_vector_2_length= 0;

int read_value(){
        int aux = 0;

        printf("\n Give value= ");
        scanf("%d",&aux);

        return aux;
}

void read_vector(int vector[], int vector_length){
        int iterator = 0;

        for (iterator = 0;iterator < vector_length; iterator++){
                printf("\n vector[%d]=",iterator);
                scanf("%d",&vector[iterator]);
        }
}

void write_vector(int vector[], int vector_length){
        int iterator = 0;

        printf("\n Vector: ");
        for (iterator = 0; iterator < vector_length; iterator++){
                printf("%d ",vector[iterator]);
        }
}

void merge_vectors(int vector_1[], int vector_1_length,int vector_2[],int vector_2_length){
        int vector_1_iterator = 0;
        int vector_2_iterator = 0;
        int vector_sorted_iterator = 0;

        // we compare an element from the first vector with an element from the second vector
        // the element with the smallest value is added to the sorted/merged vector
        while ((vector_1_iterator < vector_1_length) && (vector_2_iterator < vector_2_length)) {
               if (vector_1[vector_1_iterator] < vector_2[vector_2_iterator]) {
                       g_vector_sorted[vector_sorted_iterator] = vector_1[vector_1_iterator];
                       vector_1_iterator++;
               }else{
                       g_vector_sorted[vector_sorted_iterator] = vector_2[vector_2_iterator];
                       vector_2_iterator++;
               }
               vector_sorted_iterator++;
        }

        // if one of the vectors reaches the end
        // the elements from the other vectors get copied to the sorted/merged vector

        if (vector_1_iterator < vector_1_length){
               while (vector_1_iterator < vector_1_length){
                       g_vector_sorted[vector_sorted_iterator] = vector_1[vector_1_iterator];
                       vector_1_iterator++;
                       vector_sorted_iterator++;
               }
        }else{
               while (vector_2_iterator < vector_2_length){
                       g_vector_sorted[vector_sorted_iterator] = vector_2[vector_2_iterator];
                       vector_2_iterator++;
                       vector_sorted_iterator++;
               }
        }
}

int find_min_value(int vector[],int vector_length){
        int iterator = 0;
        int min = vector[0];

        for (iterator=0;iterator < vector_length;iterator++) {
               if (vector[iterator] < min) {
                       min = vector[iterator];
               }
        }

        return min;
}

int main(){

        //read vectors
        g_vector_1_length = read_value();
        read_vector(g_vector_1,g_vector_1_length);
        write_vector(g_vector_1,g_vector_1_length);
        g_vector_2_length = read_value();
        read_vector(g_vector_2,g_vector_2_length);
        write_vector(g_vector_2,g_vector_2_length);

        //merge the vectors
        g_vector_sorted_length = g_vector_1_length + g_vector_2_length;
        merge_vectors(g_vector_1,g_vector_1_length,g_vector_2,g_vector_2_length);
        write_vector(g_vector_sorted,g_vector_sorted_length);

        //find the minimum value in a vector
        printf("\n The minimum value in the vector is= %d",find_min_value(g_vector_sorted,g_vector_sorted_length));

        return 0;
}

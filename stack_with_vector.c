#include <stdio.h>
#include <stdlib.h>

#define MAX 1000



void list_vector(int *vector_start,int vector_length){

       int iterator = 0;



       printf("Vector: \n");

       for (iterator =0 ; iterator < vector_length-1; iterator++) {

               printf("%d ",*(vector_start + iterator)); // vector[iterator]

       }

}

/*void push_element_begining(int *vector, int new_value, int vector_length){

        vector_length++;

        int i,aux=vector[0];

        vector[0]=new_value;



        for(i = 0;i < vector_length-1; i++){

            vector[i+1]=aux;

            aux=vector[i+2];

        }

}*/

void push_element_begining(int *vector, int new_value, int &vector_length){

        int i;

        for(i=vector_length;i>=1;i--){

            vector[i]=vector[--i];

        }

        vector[0]=new_value;

}

int main()

{  int *vector[MAX];

    push_element_begining(vector,2,2);

    list_vector(vector,1);

    push_element_begining(vector,4,3);

    push_element_begining(vector,6,4);

    list_vector(vector,3);

    return 0;

}

main.txt
Open with
Displaying main.txt.

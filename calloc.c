#include <stdio.h>
#include <stdlib.h>

int main(){
       int num = 0;
       int iterator = 0;
       int *ptr;
       int sum = 0;

       printf("Enter number of elements: ");
       scanf("%d", &num);

       ptr = calloc(num, sizeof(int));  //memory allocated using calloc
       if(ptr == NULL){
               printf("Error! memory not allocated.");
               exit(0);
       }

       printf("Enter elements of array: ");
       for(iterator = 0; iterator < num; iterator++){
               scanf("%d", ptr + iterator);
               sum += *(ptr + iterator);
       }

       printf("Sum = %d", sum);
       free(ptr);
       return 0;
}

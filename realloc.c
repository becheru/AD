#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;
    int iterator = 0;
    int nr1 = 0;
    int nr2 = 0;

    printf("Enter size of array: ");
    scanf("%d", &nr1);

    ptr = malloc(nr1 * sizeof(int));

    printf("Address of previously allocated memory: ");
    for(iterator = 0; iterator < nr1; iterator++)
               printf("%x\t",ptr + iterator);

    printf("\nEnter new size of array: ");
    scanf("%d", &nr2);

    ptr = realloc(ptr, nr2);   //reallocate the memeory dynamically

    for(iterator = 0; iterator < nr2; iterator++)
               printf("\n%x", ptr + iterator);

    return 0;
}

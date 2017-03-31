#include <stdio.h>

int revenue(int  *salary, int bonus){
       int total = 0;

       total = *salary + bonus;
       return total;
}

int main(){
       int salary = 0;
       int bonus = 0;

       printf("Enter the employee current salary:");
       scanf("%d", &salary);
       printf("Enter bonus amount:");
       scanf("%d", &bonus);

       int op = revenue(&salary, bonus);
       printf("Final salary: %d", op);

       return 0;
}

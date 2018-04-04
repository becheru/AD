#include <stdio.h>
#include <stdlib.h>

struct g_node{
       int info;
       struct g_node *next;
       struct g_node *previous;
};

void push_element_begining(struct g_node *head ,int new_element_value){
       struct g_node *new_element = malloc(sizeof(struct g_node));
       struct g_node *second_element = head->next;

       new_element->next = second_element;
       second_element->previous = new_element;
       head->next = new_element;
       new_element->previous = head;
       new_element->info = new_element_value;
}

void print_list(struct g_node *head){
       struct g_node *iterator = head;

       printf("\n List: ");
       while (iterator->next != NULL) {
               printf("%d ", iterator->next->info);
               iterator = iterator->next;
       }
}

int main(){
       struct g_node *head = malloc(sizeof(struct g_node));

       head->next = NULL;
       head->previous = NULL;
       push_element_begining(head, 2);
       push_element_begining(head, 3);
       print_list(head);
       free(head);

       return 0;

}

#include <stdio.h>
#include <stdlib.h>

struct g_node{
       int info;
       struct g_node *next;
};

void push_element_begining(struct g_node *head ,int new_element_value){
       struct g_node *new_element = malloc(sizeof(struct g_node));

       new_element->info = new_element_value;
       new_element->next = head->next;
       head->next = new_element;
}

void push_element_end(struct g_node *head ,int new_element_value){
       struct g_node *new_element = malloc(sizeof(struct g_node));
       struct g_node *iterator = head;
       struct g_node *last_element;

       while (iterator->next != NULL) {
               iterator = iterator->next;
       }
       last_element = iterator;

       last_element->next = new_element;
       new_element->info = new_element_value;
       new_element->next = NULL;
}

void print_list(struct g_node *head){
       struct g_node *iterator = head;

       printf("\n List: ");
       while (iterator->next != NULL) {
               printf("%d ", iterator->next->info);
               iterator = iterator->next;
       }
}

///to be implemented
int find_postion_of_value(struct g_node *head ,int searched_element_value){
       int position = -1;

       return position;
}

///to be implemented
void push_element(struct g_node *head ,int new_element_value, int position){

}

///to be implemented
void pop_element(struct g_node *head ,int new_element_value, int position){

}

///to be implemented
int pop_element_begining(struct g_node *head){
       struct g_node *poped_element;

}

///to be implemented
int pop_element_end(struct g_node *head){
       struct g_node *poped_element;

}

int main(){
       struct g_node *head = malloc(sizeof(struct g_node));

       head->next = NULL;
       push_element_begining(head, 2);
       push_element_begining(head, 3);
       push_element_end(head,4);
       print_list(head);
       free(head);

       return 0;

}

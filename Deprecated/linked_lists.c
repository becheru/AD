#include <stdio.h>
#include <stdlib.h>

struct g_node{
       int info;
       struct g_node *next;
};

void push_element_begining(struct g_node *head ,int new_element_value){
       struct g_node *new_element = malloc(sizeof(struct g_node));

       new_element->next = head->next;
       head->next = new_element;
       new_element->info = new_element_value;
}

void push_element_end(struct g_node *head ,int new_element_value){
       struct g_node *new_element = malloc(sizeof(struct g_node));
       struct g_node *iterator = head;
       struct g_node *last_element;

       while (iterator->next != NULL) {
               iterator = iterator->next;
       }
       last_element = iterator;

       new_element->next = last_element->next;
       last_element->next = new_element;
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

///to be implemented
int find_postion_of_value(struct g_node *head ,int searched_element_value){
       // finds the position of an element in a list
       // return -1 in case the searched_element_value is not in list
       int position = -1;

       return position;
}

///to be implemented
void push_element(struct g_node *head ,int new_element_value, int position){
       //push new_element_value at a certain position in the list

}

///to be implemented
int pop_element(struct g_node *head ,int new_element_value, int position){
       struct g_node *poped_element;
       //remove new_element_value from certain position in the list and
       //return its value
}

///to be implemented
int pop_element_begining(struct g_node *head){
       //remove new_element_value from the begining and return its value
       struct g_node *poped_element;

}

///to be implemented
int pop_element_end(struct g_node *head){
       //remove new_element_value from the end and return its value
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

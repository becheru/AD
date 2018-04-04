//
// Created by Alexandru Becheru on 20/03/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

///to be implemented
void push_element_at_position(struct g_node *head, int position, int new_element_value){

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
int find_postion_of_value(struct g_node *head ,int element_value){
    int position = -1; //list is empty
    struct g_node *iterator = head;
    int element_found = 0;

    ///to be implemented

    if (element_found == 1){
        return position;
    }else{
        return -2; // not found in list
    }

}

///to be implemented
int pop_element_begining(struct g_node *head){
    struct g_node *poped_element;
    int aux;

    ///to be implemented

    return aux;
}

///to be implemented
int pop_element_end(struct g_node *head){
    struct g_node *poped_element;
    struct g_node *iterator;
    int aux;

    ///to be implemented

    return aux;
}

///to be implemented
int pop_element_at_position(struct g_node *head, int position){
    struct g_node *iterator;
    struct g_node *poped_element;
    struct g_node *previous_element;
    int current_position;
    int aux;

    ///to be implemented

    return aux;
}

///to be implemented
int return_no_elements(struct g_node *head){
    int no_elements ;
    struct g_node *iterator;
    iterator = head;
    no_elements = 0;

    ///to be implemented

    return no_elements;
}

int main(){
    struct g_node *head = malloc(sizeof(struct g_node));
    int aux;
    int aux2;

    head->next = NULL;

    printf("\n===== Pushing at the begining ======");
    push_element_begining(head, 1);
    print_list(head);
    push_element_begining(head, 2);
    print_list(head);

    printf("\n===== Pushing at the end ======");
    push_element_end(head, 3);
    print_list(head);

    printf("\n===== Pushing at specific position ======");
    print_list(head);
    push_element_at_position(head,3,10);
    print_list(head);

    printf("\n===== No elements in list ======");
    aux = return_no_elements(head);
    printf("\nThe list has %d elments ", aux);

    printf("\n===== Finding the position of a specific element ======");
    printf("\nGive the searched element's value: ");
    scanf("%d",&aux);
    aux2 = find_postion_of_value(head,aux);
    printf("\nThe position of element %d is %d", aux, aux2);

    printf("\n===== Poping from the begining ======");
    aux = pop_element_begining(head);
    printf("\n The poped element is %d",aux);
    print_list(head);

    printf("\n===== Poping from the end ======");
    aux = pop_element_end(head);
    printf("\n The poped element is %d",aux);
    print_list(head);

    printf("\n===== Poping from specific position ======");
    push_element_begining(head,2);
    push_element_begining(head,3);
    print_list(head);
    aux = pop_element_at_position(head,0);
    printf("\n The poped element is %d",aux);
    print_list(head);

    free(head);

    return 0;
}

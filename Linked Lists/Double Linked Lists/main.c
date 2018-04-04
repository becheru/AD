//
// Created by Alexandru Becheru on 20/03/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct g_node{
    int info;
    struct g_node *next;
    struct g_node *previous;
};

void interchange_nodes_values(struct g_node *node_1, struct g_node *node_2){
    int aux;

    aux = node_1->info;
    node_1->info = node_2->info;
    node_2->info = aux;
}

void push_element_begining(struct g_node *head, struct g_node *tail ,int new_element_value){
    struct g_node *new_element;
    new_element = malloc(sizeof(struct g_node));
    new_element->info = new_element_value;
    struct g_node *next_element;

    next_element = head->next;
    if (next_element != NULL){
        next_element->previous = new_element;
    }
    new_element->next = next_element;
    new_element->previous = head;
    head->next = new_element;
    head->info++;
}

int get_no_elements(struct g_node *head, struct g_node *tail){
    int no_elements ;
    struct g_node *iterator_left;
    struct g_node *iterator_right;

    if (head->next == tail){
        return 0;
    }
    iterator_left = head->next;
    iterator_right = tail->previous;
    no_elements = 0;
    while ( 1 > 0 ){
        if (iterator_left == iterator_right){
            return no_elements + 1;
        }
        if (iterator_left->next == iterator_right){
            return  no_elements + 2;
        }
        no_elements = no_elements + 2;
        iterator_left = iterator_left->next;
        iterator_right= iterator_right->previous;
    }
}

void push_element_end(struct g_node *head ,struct g_node *tail ,int new_element_value){
    struct g_node *new_element;
    struct g_node *last_element;
    new_element = malloc(sizeof(struct g_node));
    new_element->info = new_element_value;
    last_element = tail->previous;

    new_element->next = tail;
    new_element->previous = last_element;
    tail->previous = new_element;
    last_element->next = new_element;
    head->info++;
}

void push_element_at_position(struct g_node *head, struct g_node *tail, int position, int new_element_value){
    int no_elements;
    int current_positon;
    struct g_node *iterator;
    struct g_node *previous_element;
    struct g_node *next_element;
    struct g_node *new_element;

    no_elements = head->info;
    assert(position >= 0);
    assert(position <= no_elements);

    if (position <= no_elements/2){
        current_positon = 0;
        iterator = head;
        while (current_positon < position){
            iterator = iterator->next;
            current_positon++;
        }
        previous_element = iterator;
        next_element = iterator->next;
    }else{
        current_positon = no_elements;
        iterator = tail;
        while (current_positon > position){
            iterator = iterator->previous;
            current_positon--;
        }
        previous_element = iterator->previous;
        next_element = iterator;
    }

    new_element = malloc(sizeof(struct g_node));
    new_element->info = new_element_value;
    new_element->next = next_element;
    new_element->previous = previous_element;
    next_element->previous = new_element;
    previous_element->next = new_element;
    head->info++;
}

void print_list(struct g_node *head, struct g_node *tail){
    struct g_node *iterator = head;

    printf("\n List: ");
    while (iterator->next != tail) {
        printf("%d ", iterator->next->info);
        iterator = iterator->next;
    }
}

void print_list_reverse(struct g_node *head, struct g_node *tail){
    struct g_node *iterator;

    iterator = tail;
    printf("\n List: ");
    while (iterator->previous != head) {
        printf("%d ", iterator->previous->info);
        iterator = iterator->previous;
    }
}

int pop_element_begining(struct g_node *head, struct g_node *tail){
    struct g_node *poped_element;
    struct g_node *next_element;
    int aux;

    assert(head->next != tail);

    poped_element = head->next;
    next_element = head->next->next;
    head->next = next_element;
    next_element->previous = head;
    aux = poped_element->info;
    free(poped_element);
    head->info--;

    return aux;
}

int pop_element_end(struct g_node *head, struct g_node *tail){
    struct g_node *poped_element;
    struct g_node *previous_element;
    int aux;

    assert(head->next != tail);

    previous_element = tail->previous->previous;
    poped_element = tail->previous;
    aux = poped_element->info;
    previous_element->next = tail;
    tail->previous = previous_element;
    free(poped_element);
    head->info--;

    return aux;
}

///to be implemented
int pop_element_at_position(struct g_node *head, struct g_node *tail, int position){
    int no_elements;
    int current_positon;
    int aux;
    struct g_node *iterator;
    struct g_node *previous_element;
    struct g_node *next_element;
    struct g_node *poped_element;

    no_elements = head->info;
    assert(position >= 0);
    assert(position < no_elements);

    if (position <= no_elements/2){
        current_positon = 0;
        iterator = head;
        while (current_positon < position){
            iterator = iterator->next;
            current_positon++;
        }
        previous_element = iterator;
        poped_element = iterator->next;
        next_element = iterator->next->next;
    }else{
        current_positon = no_elements-1;
        iterator = tail;
        while (current_positon > position){
            iterator = iterator->previous;
            current_positon--;
        }
        previous_element = iterator->previous->previous;
        poped_element = iterator->previous;
        next_element = iterator;
    }

    aux = poped_element->info;
    previous_element->next = next_element;
    next_element->previous = previous_element;
    free(poped_element);
    head->info--;

    return aux;
}

void empty_list(struct g_node *head, struct g_node *tail){
    struct g_node *iterator_left;
    struct g_node *iterator_right;

    assert(head->next != tail);
    iterator_left = head->next;
    iterator_right = tail->previous;

    while( 1 > 0){
        if (iterator_left == iterator_right){
            free(iterator_left);
            break;
        }
        if (iterator_left->next == iterator_right){
            free(iterator_left);
            free(iterator_right);
            break;
        }
        iterator_left = iterator_left->next;
        free(iterator_left->previous);
        iterator_right = iterator_right->previous;
        free(iterator_right->next);
    }

    head->next = tail;
    head->info = 0;
    tail->previous = head;
}

//to be implemented
void selection_sort(struct g_node *head){
    struct g_node *min;
    struct g_node *iterator_1;
    struct g_node *iterator_2;

    //list is empty
    assert(head->next != NULL);
    //list has only one element
    assert(head->next->next != NULL);

    for(iterator_1 = head->next; iterator_1->next != NULL; iterator_1 = iterator_1->next){
        min = iterator_1;
        for (iterator_2 = iterator_1->next; iterator_2 != NULL; iterator_2 = iterator_2->next) {
            if (iterator_2->info < min->info){
                min = iterator_2;
            }
        }
        if (min->info < iterator_1->info){
            interchange_nodes_values(min,iterator_1);
        }
    }
}

int main(){
    struct g_node *head = malloc(sizeof(struct g_node));
    struct g_node *tail = malloc(sizeof(struct g_node));
    int aux;
    int aux2;

    head->previous = NULL;
    head->next = tail;
    head->info = 0;
    tail->previous = head;
    tail->next = NULL;

    printf("\n===== Pushing at the begining ======");
    push_element_begining(head, tail, 1);
    print_list(head,tail);
    push_element_begining(head, tail, 2);
    print_list(head,tail);
    push_element_begining(head, tail, 3);
    print_list(head, tail);

    printf("\n===== Printing reverse ======");
    print_list_reverse(head, tail);

    printf("\n===== Pushing at the end ======");
    print_list(head, tail);
    push_element_end(head, tail, 4);
    print_list(head, tail);
    push_element_end(head, tail, 5);
    print_list(head, tail);
    push_element_end(head, tail, 6);
    print_list(head, tail);

    printf("\n===== No elements in list ======");
    aux = get_no_elements(head, tail);
    printf("\nThe list has %d elements ", aux);
    printf("\nThe list has %d elements ", head->info);

    printf("\n===== Pushing at specific position ======");
    print_list(head, tail);
    push_element_at_position(head,tail,4,10);
    print_list(head, tail);

    printf("\n===== Poping from the begining ======");
    print_list(head, tail);
    aux = pop_element_begining(head, tail);
    printf("\n The poped element is %d",aux);
    print_list(head, tail);

    printf("\n===== Poping from the end ======");
    print_list(head, tail);
    aux = pop_element_end(head, tail);
    printf("\n The poped element is %d",aux);
    print_list(head, tail);

    printf("\n===== Poping from specific position ======");
    print_list(head, tail);
    aux = pop_element_at_position(head, tail, 4);
    printf("\n The poped element is %d",aux);
    print_list(head, tail);

    printf("\n===== No elements in list ======");
    aux = get_no_elements(head, tail);
    printf("\nThe list has %d elements ", aux);
    printf("\nThe list has %d elements ", head->info);

    printf("\n===== Empty list ======");
    print_list(head, tail);
    selection_sort(head);
    print_list(head, tail);

    printf("\n===== Selection Sort ======");
    print_list(head, tail);
    empty_list(head, tail);
    print_list(head, tail);

    printf("\n===== Queue (FIFO) ======");
    push_element_begining(head, tail, 1);
    push_element_begining(head, tail, 2);
    push_element_begining(head, tail, 3);
    print_list(head, tail);
    pop_element_end(head, tail);
    print_list(head,tail);
    empty_list(head, tail);

    printf("\n===== Stack (LIFO) ======");
    push_element_begining(head, tail, 1);
    push_element_begining(head, tail, 2);
    push_element_begining(head, tail, 3);
    print_list(head, tail);
    pop_element_begining(head, tail);
    print_list(head,tail);
    empty_list(head, tail);

    free(head);
    free(tail);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _node_t
{
    void *value;
    struct _node_t *next;
} node_t;

typedef struct
{
    node_t *root;
} list_t;

typedef node_t *list_iter_t;

typedef void *(*fn)(void *);

node_t *mk_node(void *value, node_t *next)
{
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->value = value;
    node->next = next;
    return node;
}

void node_free(node_t *node)
{
    free(node);
}

list_t *mk_list()
{
    list_t *list = (list_t *) malloc(sizeof(list_t));
    list->root = NULL;
    return list;
}

void list_free(list_t *list)
{
    free(list);
}

bool list_empty(list_t *list)
{
    return list->root == NULL;
}

void list_add(list_t *list, void *value)
{
    node_t *aux = mk_node(value, list->root);
    list->root = aux;
}

list_t *list_reverse(list_t *list)
{
    list_t *result = mk_list();
    node_t *aux = list->root;
    while (aux)
    {
        list_add(result, aux->value);
        aux = aux->next;
    }
    return result;
}

list_iter_t list_iter_first(list_t *list)
{
    return list->root;
}

bool list_iter_has_next(list_iter_t it)
{
    return it != NULL;
}

void list_iter_next(list_iter_t *it)
{
    assert(it != NULL);
    *it = (*it)->next;
}

void *list_iter_value(list_iter_t it)
{
    assert(it != NULL);
    return it->value;
}

list_t *map(list_t *list, fn f)
{
    list_t *result = mk_list();
    node_t *aux = list->root;
    while (aux)
    {
        list_add(result, f(aux->value));
        aux = aux->next;
    }
    return list_reverse(result);
}

void *add1(void *n)
{
    return (void *) ((int) n + 1);
}

int main(int argc, const char *argv[])
{
    list_t *l = mk_list();
    assert(list_empty(l));
    list_add(l, 1);
    list_add(l, 2);
    list_add(l, 3);
    assert(!list_empty(l));

    for (list_iter_t it = list_iter_first(l); list_iter_has_next(it); list_iter_next(&it))
        printf("%d\n", (int) list_iter_value(it));

    list_t *m = map(l, add1);

    for (list_iter_t it = list_iter_first(m); list_iter_has_next(it); list_iter_next(&it))
        printf("%d\n", (int) list_iter_value(it));

    return 0;
}

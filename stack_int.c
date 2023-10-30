#include <stdlib.h>

#include "stack_int.h"

struct _node {
    int value;
    struct _node *next;
};

typedef struct _node node;

struct _stack_int {
    node *top;
};

stack_int *stack_int_new() {
    stack_int *s = malloc(sizeof(stack_int));
    s->top = NULL;
    return s;
}

void stack_int_delete(stack_int **_s) {
    stack_int *s = *_s;
    node *n = s->top;
    while (n != NULL) {
        node *next = n->next;
        free(n);
        n = next;
    }
    free(s);
    *_s = NULL;
}

int stack_int_empty(stack_int *s) {
    return s->top == NULL;
}

void stack_int_push(stack_int *s, int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = s->top;
    s->top = n;
}

int stack_int_pop(stack_int *s) {
    node *n = s->top;
    s->top = n->next;
    int value = n->value;
    free(n);
    return value;
}

// Aula 14a ex2
int stack_int_genpop(stack_int *s, int index) {
    // Get size
    int size = 0;
    for (node *n = s->top; n != NULL; n = n->next) {
        size++;
    }

    // Get node to remove and get value
    node *n = s->top;
    node *prev = NULL;
    for (int i = 0; i < size - index; i++) {
        prev = n;
        n = n->next;
    }

    // If node to remove is the first one, update top
    if (prev == NULL) {
        s->top = n->next;
    } else { // Else, update previous node next to skip the node to remove
        prev->next = n->next;
    }

    int value = n->value; 
    free(n); // Free node

    return value;
}

// Aula 14a ex4
void stack_int_push_improv(stack_int *s, int value, int index) {
    node *prev = NULL;
    node *n = s->top;
    for (int i = 0; i < index; i++) {
        prev = n;
        n = n->next;
    }

    node *new = malloc(sizeof(node));
    new->value = value;

    if (prev == NULL) {
        new->next = s->top;
        s->top = new;
    } else {
        new->next = n;
        prev->next = new;
    }
}

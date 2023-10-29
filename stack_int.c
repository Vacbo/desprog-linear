#include <stdlib.h>

#include "stack_int.h"

struct _stack_int {
    int capacity;
    int *data;
    int size;
};

stack_int *stack_int_new(int capacity) {
    stack_int *s = malloc(sizeof(stack_int));
    s->capacity = capacity;
    s->data = malloc(capacity * sizeof(int));
    s->size = 0;
    return s;
}

void stack_int_delete(stack_int **_s) {
    stack_int *s = *_s;
    free(s->data);
    free(s);
    *_s = NULL;
}

int stack_int_empty(stack_int *s) {
    return s->size == 0;
}

int stack_int_full(stack_int *s) {
    return s->size == s->capacity;
}

void stack_int_push(stack_int *s, int value) {
    s->data[s->size] = value;
    s->size++;
}

int stack_int_pop(stack_int *s) {
    s->size--;
    return s->data[s->size];
}

// Aula 14a ex1
int stack_int_genpop(stack_int *s, int index) {
    int value = s->data[index];
    for (int i = index; i < s->size - 1; i++) {
        s->data[i] = s->data[i + 1];
    }
    s->size--;
    return value;
}

// Aula 14a ex3
void stack_int_push_improv(stack_int *s, int value, int index) {
    int i;
    for (i = s->size; i > index; i--) {
        s->data[i] = s->data[i - 1];
    }
    s->data[i] = value;
    s->size++;
}
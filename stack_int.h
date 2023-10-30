#ifndef STACK_INT_H
#define STACK_INT_H

struct _stack_int;

typedef struct _stack_int stack_int;

stack_int *stack_int_new();
void stack_int_delete(stack_int **_s);
int stack_int_empty(stack_int *s);
void stack_int_push(stack_int *s, int value);
int stack_int_pop(stack_int *s);

// Aula 14a ex2
int stack_int_genpop(stack_int *s, int index);

// Aula 14a ex4
void stack_int_push_improv(stack_int *s, int value, int index);

#endif

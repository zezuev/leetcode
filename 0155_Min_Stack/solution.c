/* The idea is to store the current minimum as part of stack items. */

#include <stdlib.h>

typedef struct item {
    struct item *next;
    struct item *prev;
    int val;
    int min_val;
} Item;

typedef struct {
    Item *head;
    Item *tail;
} MinStack;

Item *
item_create(int val, int min_val)
{
    Item *new_item = (Item *)malloc(sizeof(Item));
    if (!new_item) return NULL;
    new_item->next = NULL;
    new_item->prev = NULL;
    new_item->val = val;
    new_item->min_val = min_val;
    return new_item;
}

MinStack *
min_stack_create()
{
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    if (!stack) return NULL;
    stack->head = NULL;
    stack->tail = NULL;
    return stack;
}

void
min_stack_push(MinStack *stack, int val)
{
    int min_val = val;
    if (stack->tail && stack->tail->min_val < min_val) {
        min_val = stack->tail->min_val;
    }
    Item *new_item = item_create(val, min_val);
    if (!new_item) return;

    if (stack->tail) {
        stack->tail->next = new_item;
        new_item->prev = stack->tail;
        stack->tail = new_item;
    } else {
        stack->head = stack->tail = new_item;
    }
}

void
min_stack_pop(MinStack *stack)
{
    if (!stack->tail) return;
    if (stack->head == stack->tail) {
        free(stack->head);
        stack->head = stack->tail = NULL;
    } else {
        Item *pop = stack->tail;
        pop->prev->next = NULL;
        stack->tail = pop->prev;
        free(pop);
    }
}

int
min_stack_top(MinStack *stack)
{
    return stack->tail->min_val;
}

int
min_stack_get_min(MinStack *stack)
{
    return stack->tail->min_val;
}

void
min_stack_free(MinStack *stack)
{
    Item *current = stack->head;
    while (current) {
        Item *next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
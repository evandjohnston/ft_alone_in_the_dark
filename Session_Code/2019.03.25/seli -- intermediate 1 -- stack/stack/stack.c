#include <stdlib.h>

struct s_node {
    void          *content;
    struct s_node *next;
};

struct s_stack {
    struct s_node *top;
};

struct s_stack *init(void)
{
    struct s_stack *s;
    s = malloc(sizeof(struct s_stack));
    if (s)
        s->top = NULL;
    return s;
}

void *pop(struct s_stack *stack)
{
    if (!stack->top)
        return NULL;

    struct s_node *top = stack->top;
    stack->top = top->next;
    return top;
}

void push(struct s_stack *stack, void *content)
{
    struct s_node *n;
    n = malloc(sizeof(struct s_node));
    n->content = content;
    n->next = stack->top;

    stack->top = n;
}

void *peek(struct s_stack *stack)
{
    return stack->top;
}

int isEmpty(struct s_stack *stack)
{
    return stack->top ? 0 : 1;
}


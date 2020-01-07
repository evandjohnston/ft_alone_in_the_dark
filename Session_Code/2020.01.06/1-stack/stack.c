// Passed Moulinette 2019.09.01

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
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	if (stack->top == NULL)
		return (NULL);
	struct s_node *cur = stack->top;
	void *content = cur->content;
	stack->top = cur->next;
	free(cur);
	return (content);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *cur = malloc(sizeof(struct s_node));
	cur->content = content;
	cur->next = stack->top;
	stack->top = cur;
}

void *peek(struct s_stack *stack)
{
	if (stack->top == NULL)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}



// //--------------------------------------------
#include <stdio.h>
int 	main(void)
{
	char a[] = "aaaaa";			(void)a;
	char b[] = "bbbbb";			(void)b;
	char c[] = "ccccc";			(void)c;
	char d[] = "ddddducks";		(void)d;
	struct s_stack *stack;

	stack = init(); 			(void)stack;
	printf("isEmpty: %d\n", isEmpty(stack));
	printf("peek: %s\n", peek(stack));
	printf("pop: %s\n", pop(stack));
	push(stack, a); push(stack, b); push(stack, c); push(stack, d);
	printf("isEmpty: %d\n", isEmpty(stack));
	printf("peek: %s\n", peek(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("isEmpty: %d\n", isEmpty(stack));

	return (0);
}
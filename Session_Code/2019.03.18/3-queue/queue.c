struct s_node {
    void *content;
    struct s_node *next;
};
struct s_queue {
    struct s_node *first;
    struct s_node *last;
};

#include <stdlib.h>
#include <string.h>
struct s_queue *init(void)
{
	struct s_queue *list = malloc(sizeof(struct s_queue *));
	list->first = NULL;
	list->last = NULL;
	return (list);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->next = NULL;
	node->content = content;

	if (queue->first == NULL)
		queue->first = node;
	else
		queue->last->next = node;
	queue->last = node;
}

void *dequeue(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	void *content = queue->first->content;
	struct s_node *node = queue->first;
	if (queue->last == queue->first)
		queue->last = NULL;
	queue->first = queue->first->next;
	free(node);
	return (content);
}

void *peek(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (1);
	else
		return (0);
}

#include <stdio.h>
int main(void)
{
	char a[] = "aaaa";
	char b[] = "bbbb";
	char c[] = "cccc";

	struct s_queue *list = init();
	printf("Is empty at beginning? %d\n", isEmpty(list));
	enqueue(list, a);
	printf("Is empty after adding a? %d\n", isEmpty(list));
	enqueue(list, b);
	enqueue(list, c);
	printf("peek: %s\n", peek(list));
	printf("dequeue 1: %s\n", dequeue(list));
	printf("dequeue 2: %s\n", dequeue(list));
	printf("dequeue 3: %s\n", dequeue(list));
	printf("dequeue 4: %s\n", dequeue(list));
	printf("Is empty at end? %d\n", isEmpty(list));
}
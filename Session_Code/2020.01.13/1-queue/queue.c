#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void)
{
	// Initialize the queue.
	// The first and last pointers are set to NULL.
	struct s_queue *new = malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *cur = malloc(sizeof(struct s_node));
	cur->next = NULL;
	cur->content = content;

	if (queue->first == NULL)
		queue->first = cur;
	else
		queue->last->next = cur;
	queue->last = cur;
}

void *dequeue(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	struct s_node *cur = queue->first;
	void *content = cur->content;
	queue->first = cur->next;
	if (queue->first == NULL)
		queue->last = NULL;
	free(cur);
	return (content);
}

void *peek(struct s_queue *queue)
{
	// peek(queue) : Return the first item of the queue.
	// If the queue is empty, the function returns NULL.
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (queue->first != NULL)
		return (0);
	return (1);
}

#include <stdio.h>
int main(void)
{
	char a[] = "Apples"; (void)a;
	char b[] = "Banananananas"; (void)b;
	char c[] = "Charlemagne"; (void)c;
	char d[] = "ddddduodenum"; (void)d;

	struct s_queue *queue = init();
	printf("isEmpty A: %d\n", isEmpty(queue));
	enqueue(queue, a);
	printf("isEmpty B: %d\n", isEmpty(queue));
	enqueue(queue, b);
	enqueue(queue, c);
	enqueue(queue, d);

	printf("Peek: %s\n", peek(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Peek: %s\n", peek(queue));
	printf("isEmpty C: %d\n", isEmpty(queue));
	return (0);
}
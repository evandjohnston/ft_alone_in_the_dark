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

//----------------------------
#include <stdio.h>

struct s_map {
	char	**map;
	int		rows;
	int		cols;
};

int main(void)
{
//Set up some strings to be put into queue
	char a[] = "aaaa";
	char b[] = "bbbb";
	char c[] = "cccc";

//Create a struct containing two ints and a 2-d array of chars
	struct s_map *mapinfo = malloc(sizeof(struct s_map *));
	mapinfo->rows = 3;
	mapinfo->cols = 4;
	mapinfo->map = malloc(sizeof(char *) * mapinfo->rows);
	mapinfo->map[0] = c;
	mapinfo->map[1] = b;
	mapinfo->map[2] = a;

//Create the queue and put stuff into it
	struct s_queue *list = init();
	printf("Is empty at beginning? %d\n", isEmpty(list));
	enqueue(list, mapinfo);
	printf("Is empty after adding mapinfo? %d\n", isEmpty(list));
	enqueue(list, a);
	enqueue(list, b);
	enqueue(list, c);

//Peek with inline typecasting (hard to read, but fewer lines)
	printf("peek cols with typecasting: %d\n", ((struct s_map *)peek(list))->cols);

//Peek with assigning to variable:
	struct s_map *check_map_info = peek(list);
	printf("peek rows with assigning to variable: %d\n", check_map_info->rows);

//Dequeue items from list with inline typecasting:
	printf("dequeue 1: %s\n", ((struct s_map *)dequeue(list))->map[0]);
	printf("dequeue 2: %s\n", dequeue(list));
	printf("dequeue 3: %s\n", dequeue(list));
	printf("dequeue 4: %s\n", dequeue(list));
	printf("Is empty at end? %d\n", isEmpty(list));
}
#include "ft_list.h"

#ifdef TEST
#include <stdio.h>
#endif

// typedef struct      s_list
// {
//     struct s_list   *next;
//     void            *data;
// }                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == 0 || *begin_list == 0)
		return;

	t_list *prev = *begin_list;
	t_list *cur = prev->next;
	while (prev != 0 && cur != 0)
	{
		//remove IF data == data_ref according to cmp
		if (cmp(cur->data, data_ref) == 0)
			prev->next = cur->next;
		prev = prev->next;
		if (prev)
			cur = prev->next;
	}

	//set cur to the node pointed to by begin_list
	cur = *begin_list;
	if (cmp(cur->data, data_ref) == 0)
		*begin_list = cur->next;
}

#ifdef TEST
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_list *new_node(char *data)
{
	t_list *new = malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}

void	print_list(t_list **head)
{
	if (!head || !*head)
	{
		printf("empty list\n");
		return;
	}
	t_list *cur = *head;
	while (cur)
	{
		printf("%s -->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list *begin_list = NULL;
	char data_ref[] = "bbb";
	t_list *cur = new_node("aaa");
	cur->next = new_node("bbb");
	cur->next->next = new_node("ccc");
	cur->next->next = new_node("bbb");
	begin_list = cur;
	print_list(&begin_list);
	ft_list_remove_if(&begin_list, data_ref, strcmp);
	print_list(&begin_list);
}
#endif
#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == 0 || *begin_list == 0)
		return;

	t_list *prev = *begin_list;
	t_list *cur;

	while (/*prev != 0 &&*/ prev->next != 0)
	{
		cur = prev->next;
		if (cmp(data_ref, cur->data) == 0)
		{
			prev->next = cur->next;
			free(cur);
		}
		prev = prev->next;
	}

	prev = *begin_list;
	if (cmp(data_ref, prev->data) == 0)
	{
		*begin_list = prev->next;
		free(prev);
	}
}

#if 1
#include <stdio.h>
void	print_list(t_list *cur)
{
	while (cur)
	{
		printf("%d, ", *((int *)cur->data));
		cur = cur->next;
	}
	printf("\n");
}

int cmp(void *a, void *b)
{
	return (*(int *)a != *(int *)b);
}

int	main(void)
{
	t_list *aa = malloc(sizeof(t_list));
	int aa_int = 3;
	aa->data = &aa_int;
	aa->next = 0;

	t_list *bb = malloc(sizeof(t_list));
	int bb_int = 8;
	bb->data = &bb_int;
	bb->next = 0;

	t_list *cc = malloc(sizeof(t_list));
	int cc_int = 4;
	cc->data = &cc_int;
	cc->next = 0;

	t_list *dd = malloc(sizeof(t_list));
	int dd_int = 5;
	dd->data = &dd_int;
	dd->next = 0;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	int ref = 5;
	t_list **begin_list = &aa;
	print_list(*begin_list);
	printf("------\n");
	ft_list_remove_if(begin_list, &ref, cmp);
	print_list(*begin_list);

	return (0);
}
#endif
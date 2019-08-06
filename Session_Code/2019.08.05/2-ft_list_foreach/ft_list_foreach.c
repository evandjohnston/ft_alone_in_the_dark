#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (begin_list == 0)
		return;

	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

#if 1
#include <stdlib.h>
#include <stdio.h>

void	terminate(void *str)
{
	((char *)str)[1] = '\0';
}

int	main(void)
{
	t_list *aa = malloc(sizeof(t_list));
	char aastr[] = "aaaaaa";
	aa->data = aastr;
	aa->next = 0;

	t_list *bb = malloc(sizeof(t_list));
	char bbstr[] = "bbbbbb";
	bb->data = bbstr;
	bb->next = 0;

	t_list *cc = malloc(sizeof(t_list));
	char ccstr[] = "cccccc";
	cc->data = ccstr;
	cc->next = 0;

	t_list *dd = malloc(sizeof(t_list));
	char ddstr[] = "dddddd";
	dd->data = ddstr;
	dd->next = 0;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	t_list *cur = aa;
	while (cur)
	{
		printf("%s, ", cur->data);
		cur = cur->next;
	}
	printf("\n");

	ft_list_foreach(aa, &terminate);

	cur = aa;
	while (cur)
	{
		printf("%s, ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
#endif
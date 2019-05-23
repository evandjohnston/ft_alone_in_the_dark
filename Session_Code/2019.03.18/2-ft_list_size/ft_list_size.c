typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

#include <stdlib.h>
#include <string.h>
int	ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);

	int i = 0;
	// t_list *node = begin_list;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

#include <stdio.h>
int	main(void)
{
	t_list *a = malloc(sizeof(t_list *));
	char achar = 'a';
	a->data = &achar;
	t_list *b = malloc(sizeof(t_list *));
	char bchar = 'b';
	b->data = &bchar;
	t_list *c = malloc(sizeof(t_list *));
	char cchar = 'c';
	c->data = &cchar;
	a->next = b;
	b->next = c;
	c->next = NULL;
	printf("%d\n", ft_list_size(a));
}
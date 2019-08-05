// Passed Moulinette 2019.08.04

#include <unistd.h>

#define MATCH(a, b) ((a == ')' && b == '(') || (a == ']' && b == '[') || (a == '}' && b == '{'))

int	ft_strlen(char *str)
{
	int i = -1;
	while (str[++i]);
	return (i);
}

int	brackets(char *str)
{
	int i = 0;
	int stack[ft_strlen(str)];

	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
			stack[++i] = *str;
		else if (*str == ')' || *str == ']' || *str == '}')
		{
			if (MATCH(*str, stack[i]) == 0)
				return (-1);
			--i;
		}
		str++;
	}
	if (i != 0)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int i = 1;
	while (i < ac)
	{
		if (brackets(av[i]) == -1)
			write(1, "Error\n", 6);
		else
			write(1, "OK\n", 3);
		++i;
	}
	return (0);
}
#include <unistd.h>

int	recurse(char *str)
{
	char c;

	if (str[0] == '(')
		 c = ')';
	else if (str[0] == '[')
		c = ']';
	else if (str[0] == '{')
		c = '}';
	else
		return (-1);

	int i = 1;
	int result;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
			return (-1);
		else if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			if ((result = recurse(str + i)) == -1)
				return (-1);
			else
				i += result;
		}
		++i;
	}

	return (-1);
}

int	brackets(char *str)
{
	int i = 0;
	int result;

	while (str[i])
	{
		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
			return (-1);
		else if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			if ((result = recurse(str + i)) == -1)
				return (-1);
			else
				i += result;
		}
		++i;
	}
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
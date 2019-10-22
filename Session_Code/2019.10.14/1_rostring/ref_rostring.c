#include <unistd.h>

void	traverseWord(char *str, int *i, int print)
{
	static int firstWord = 1;
	int len = 0;

	while (str[*i + len] != '\0' && str[*i + len] != ' ' && str[*i + len] != '\t')
		++len;

	if (print == 1)
	{
		if (firstWord == 0)
			write(1, " ", 1);
		write(1, &str[*i], len);
		firstWord = 0;
	}

	*i = *i + len;
}

void	skipSpace(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
}

void	rostring(char *str)
{
	int i = 0;
	skipSpace(str, &i);
	traverseWord(str, &i, 0);
	skipSpace(str, &i);

	while (str[i] != '\0')
	{
		traverseWord(str, &i, 1);
		skipSpace(str, &i);
	}

	i = 0;
	skipSpace(str, &i);
	traverseWord(str, &i, 1);
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
		rostring(argv[1]);

	write(1, "\n", 1);
	return (0);
}
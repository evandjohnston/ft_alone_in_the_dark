#include <unistd.h>

int	traverseWord(char *str, int i, int print, int *printSpace)
{
	// static int printSpace = 0;
	int len = 0;

	while (str[i + len] != '\0' && str[i + len] != ' ' && str[i + len] != '\t')
		++len;

	if (print == 1)
	{
		if (*printSpace == 1)
			write(1, " ", 1);
		write(1, &str[i], len);
		*printSpace = 1;
	}

	i += len;
	return (i);
}

void	skipSpace(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
}

void	rostring(char *str)
{
	int i = 0;
	int printSpace = 0;

	skipSpace(str, &i);
	i = traverseWord(str, i, 0, &printSpace);
	skipSpace(str, &i);

	while (str[i] != '\0')
	{
		 i = traverseWord(str, i, 1, &printSpace);
		skipSpace(str, &i);
	}

	i = 0;
	skipSpace(str, &i);
	i = traverseWord(str, i, 1, &printSpace);
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
		rostring(argv[1]);

	write(1, "\n", 1);
	return (0);
}

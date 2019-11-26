#include <unistd.h>

int		goto_match(char *str, int i, int step)
{
	int bracket_depth = 0;
	while (1)
	{
		if (str[i] == ']')
			bracket_depth--;
		if (str[i] == '[')
			bracket_depth++;
		if (bracket_depth == 0)
			return (i);
		i = i + step;
	}
	return (-1);
}

void	brainfuck(char *str)
{
	char arr[2048] = {0};
	int i = 0;
	int p = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '>')
			++p;
		else if (str[i] == '<')
			--p;
		else if (str[i] == '+')
			arr[p]++;
		else if (str[i] == '-')
			arr[p]--;
		else if (str[i] == '.')
			write(1, &arr[p], 1);
		else if (str[i] == '[' && arr[p] == 0)
			i = goto_match(str, i, 1);
		else if (str[i] == ']' && arr[p] != 0)
			i = goto_match(str, i, -1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		brainfuck(argv[1]);
	else
		write(1, "\n", 1);
}
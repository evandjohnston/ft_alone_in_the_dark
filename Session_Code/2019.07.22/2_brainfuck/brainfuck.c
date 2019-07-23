//Discussion led by evjohnst

#include <unistd.h>

int		goto_match(char *str, int i, int step)
{
	int bracket_depth = step;

	while (i >= 0 && i <= 2049)
	{
		i += step;
		if (bracket_depth == 0)
			return (i);
		else if (str[i] == ']')
			--bracket_depth;
		else if (str[i] == '[')
			++bracket_depth;
	}
	return (0);
}

void	brainfuck(char *str)
{
	char arr[2049] = { 0 };
	int ptr = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '>')
			++ptr;
		else if (str[i] == '<')
			--ptr;
		else if (str[i] == '+')
			++(arr[ptr]);
		else if (str[i] == '-')
			--(arr[ptr]);
		else if (str[i] == '.')
			write(1, &arr[ptr], 1);
		else if (str[i] == '[' && arr[ptr] == 0)
			i = goto_match(str, i, 1);
		else if (str[i] == ']' && arr[ptr] != 0)
			i = goto_match(str, i, -1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		brainfuck(argv[1]);
	return (0);
}
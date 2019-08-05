// Passed Moulinette 2019.08.04

#include <unistd.h>

int	goto_match(char *str, int i, int step)
{
	int bracket_depth = step;

	while (i >= 0 && i <= 4096)
	{
		i += step;
		if (str[i] == '[')
			++bracket_depth;
		else if (str[i] == ']')
			--bracket_depth;
		if (bracket_depth == 0)
			return (i);
	}
	return (0);
}

void	brainfuck(char *str)
{
	char arr[2049] = { [0 ... 2048] = 0 };
	int ptr = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] == '>')
			++ptr;
		else if (str[i] == '<')
			--ptr;
		else if (str[i] == '+')
			arr[ptr]++;
		else if (str[i] == '-')
			arr[ptr]--;
		else if (str[i] == '.')
			write(1, arr + ptr, 1);
		else if (str[i] == '[' && arr[ptr] == 0)
			i = goto_match(str, i, 1);
		else if (str[i] == ']' && arr[ptr] != 0)
			i = goto_match(str, i, -1);
		++i;
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
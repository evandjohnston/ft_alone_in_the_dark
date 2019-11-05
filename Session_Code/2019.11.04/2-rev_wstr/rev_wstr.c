#include <unistd.h>

void	findWordBegin(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\0')
		(*i)--;
	while (str[*i] != ' ' && str[*i] != '\t' && *i >= 0)
		(*i)--;
}

void	printWord(char *str)
{
	static int firstWord = 1;
	int i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	if (firstWord == 0)
		write(1, " ", 1);
	write(1, str, i);
	firstWord = 0;
}

void	rev_wstr(char *str)
{
	int i = 0;
	while (str[i])
		++i;

	while (i >= 0)
	{
		findWordBegin(str, &i);
		printWord(&str[i + 1]);
		--i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);

	write(1, "\n", 1);
	return (0);
}
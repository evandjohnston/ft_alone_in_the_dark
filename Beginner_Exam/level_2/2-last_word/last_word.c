// Passed Moulinette 2019.09.01

#include <unistd.h>

void	last_word(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		++i;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\0'))
		--i;
	while (i >= 0 && str[i] != ' ' && str[i] != '\t')
		--i;
	++i;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
	{
		write(1, str + i, 1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);

	write(1, "\n", 1);
	return (0);
}
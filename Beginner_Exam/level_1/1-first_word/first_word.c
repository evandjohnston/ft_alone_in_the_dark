// Passed Moulinette 2019.09.01

#include <unistd.h>

void	first_word(char *str)
{
	while (*str == ' ' || *str == '\t')
		++str;
	while (*str != '\0' && *str != ' ' && *str != '\t')
	{
		write(1, str, 1);
		++str;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		first_word(argv[1]);

	write(1, "\n", 1);
	return (0);
}
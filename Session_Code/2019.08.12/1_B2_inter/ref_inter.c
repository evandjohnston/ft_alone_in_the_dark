// Passed Moulinette 2019.08.03

#include <unistd.h>

int		find_char_n(char c, char *str, int max)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (max != -1 && i == max)
			return (0);
		if (c == str[i])
			return (1);
		++i;
	}
	return (0);
}

void	inter(char *a, char *b)
{
	int i = 0;
	while (a[i] != '\0')
	{
		if (find_char_n(a[i], b, -1) == 1 && find_char_n(a[i], a, i) == 0)
			write(1, a + i, 1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);

	write(1, "\n", 1);
	return (0);
}
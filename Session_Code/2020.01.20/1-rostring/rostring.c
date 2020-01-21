#include <unistd.h>

int		print_word(char *str, int print)
{
	static int print_space = 0;
	int i = 0;
	int word_len = 0;

	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		++i;
	while (str[i + word_len] && str[i + word_len] != ' ' && str[i + word_len] != '\t')
		++word_len;

	if (print == 1)
	{
		if (print_space)
			write(1, " ", 1);
		write(1, &str[i], word_len);
		print_space = 1;
	}

	while (str[i + word_len] && (str[i + word_len] == ' ' || str[i + word_len] == '\t'))
		++i;
	return (i + word_len);
}

void	rostring(char *str)
{
	int i = print_word(str, 0);
	while (str[i])
		i += print_word(&str[i], 1);
	print_word(str, 1);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
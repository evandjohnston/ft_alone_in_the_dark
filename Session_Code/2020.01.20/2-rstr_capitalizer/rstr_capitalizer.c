// REF_rstr_capitalizer is better although still imperfect. Read that instead. ;)

#include <unistd.h>

void	print_lower(char *str, int len)
{
	int i = 0;
	char c;
	while (i < len)
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
			c += ('a' - 'A');
		write(1, &c, 1);
		++i;
	}
}

void	print_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	write(1, &c, 1);
}

int		print_rword(char *str)
{
	int i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	{
		write(1, &str[i], 1);
		++i;
	}
	int word_len = 0;
	while (str[i + word_len] && str[i + word_len] != ' ' && str[i + word_len] != '\t')
		++word_len;

	print_lower(&str[i], word_len - 1);
	print_upper(str[i + word_len - 1]);

	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	{
		write(1, &str[i], 1);
		++i;
	}
	return (i + word_len);
}

void	rstr_cap(char *str)
{
	int i = 0;
	while (str[i])
		i += print_rword(&str[i]);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
			rstr_cap(argv[i]);
	}
	else
		write(1, "\n", 1);
	return (0);
}
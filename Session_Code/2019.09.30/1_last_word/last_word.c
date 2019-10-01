#include <unistd.h>

void	lastWord(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		++i;

// Skip any trailing whitespace
	while (i > 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\0'))
		--i;

	int wordLen = 0;
	while (str[i - wordLen] != ' ' && str[i - wordLen] != '\t' && wordLen <= i)
		++wordLen;

	if (str[0] != '\0')
		write(1, &str[i - wordLen + 1], wordLen);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		lastWord(argv[1]);

	write(1, "\n", 1);
	return (0);
}
// Passed Moulinette 2019.09.02

#include <stdlib.h>
#define ISSPACE(x) ((x) == ' ' || (x) == '\t' || (x) == '\n')

int	count_words(char *str)
{
	int n = 0;
	int i = 0;

	while (str[i])
	{
		while (str[i] && ISSPACE(str[i]))
			++i;
		if (str[i] && ISSPACE(str[i]) == 0)
			++n;
		while (str[i] && ISSPACE(str[i]) == 0)
			++i;
	}
	return (n);
}

char	*word_dupe(char *str)
{
	int len = 0;
	while (str[len] && !ISSPACE(str[len]))
		++len;
	char *word = malloc(sizeof(char) * (len + 1));
	word[len] = '\0';
	int i = 0;
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	copy_words(char *str, char **out)
{
	int n = 0;
	int i = 0;

	while (str[i])
	{
		while (str[i] && ISSPACE(str[i]))
			++i;
		if (str[i] && ISSPACE(str[i]) == 0)
		{
			out[n] = word_dupe(&str[i]);
			++n;
		}
		while (str[i] && ISSPACE(str[i]) == 0)
			++i;
	}
}

char    **ft_split(char *str)
{
	int n = count_words(str);
	char **out = malloc(sizeof(char *) * (n + 1));
	out[n] = NULL;
	copy_words(str, out);
	return(out);
}

//-----------------------------------------------------------------
#include <stdio.h>

int		main(void)
{
	// char test[] = "\njrS58VHQ	\n   	p70fL		Kx2sRP0So3E4rC9  \n nebpv3J5ousO84Pa1HjUQOImUhjwZpGn	\n \n	X28iT7Ap9 	DIYAF9ZSpKcs0Rcv\n uzO\n		\nZ7zjEeonALOKQF5xq	\n   \nQxp0b1ufFKGJ	\n2n8R9zUvZEtOwmqf\n	";
	// char test[] = "DIYAF9ZSpKcs0Rcv \n uzO\n		\nZ7zjEeonALOKQF5xq	\n   \nQxp0b1ufFKGJ	\n2n8R9zUvZEtOwmqf\n	";
	char test[] = "   word   ";

	char **arr = ft_split(test);

	if (arr[0] == NULL)
		printf("empty array\n");

	int i = 0;
	while (arr[i] != 0)
	{
		printf("[%s]\n", arr[i]);
		++i;
	}
}
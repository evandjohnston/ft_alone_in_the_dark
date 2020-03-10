#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#define TO_LOWER(c) ((c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c)

int		ft_wordlen(char *str)
{
	int len = 0;
	while (str[len] && str[len] != ' ' && str[len] != '\t')
		++len;
	return (len);
}

void	print_word(char *str)
{
	int len = ft_wordlen(str);
	write(1, str, len);
}

void	delete_word(char *str)
{
	int len = ft_wordlen(str);
	int i = 0;
	while (i < len)
	{
		str[i] = ' ';
		++i;
	}
}

int		word_cmp(char *a, char *b)
{
	//compare two words. If a is shorter than b, or they are the same 
	//length and a has a lower case-insensitive ASCII value, 
	//this function returns 1, otherwise returns 0
	int len_a = ft_wordlen(a);
	int len_b = ft_wordlen(b);
	if (len_a < len_b)
		return (1);
	else if (len_b < len_a)
		return (0);
	else
	{
		int i = 0;
		while (i < len_a)
		{
			if (TO_LOWER(a[i]) < TO_LOWER(b[i]))
				return (1);
			else if (TO_LOWER(b[i]) < TO_LOWER(a[i]))
				return (0);
			else
				++i;
		}
		return (0);
	}
}

char	*find_word(char *str)
{
	char *output_word = NULL;
	char *cur_word = NULL;
	int i = 0;
	// int res;

	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
			++i;
		if (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			if (output_word == NULL)
				output_word = &str[i];
			else
			{
				cur_word = &str[i];
				// printf("\ncomparing cur: %s to saved: %s\n", cur_word, output_word);
				if ((/*res = */word_cmp(cur_word, output_word)) == 1)
					output_word = cur_word;
				// printf("result: %d\n", res);
			}
		}
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
			++i;
	}
	return (output_word);
}

void	ord_alphlong(char *str)
{
	char *next_word;
	int first_word = 1;
	int first_line = 1;
	int word_len = 0;

	while (/*words remain*/ 1)
	{
		next_word = find_word(str);
		if (next_word == NULL)
			break;
		if (word_len < ft_wordlen(next_word))
		{
			if (first_line == 0)
				write(1, "\n", 1);
			first_line = 0;
			first_word = 1;
			word_len = ft_wordlen(next_word);
		}
		if (first_word == 0)
			write(1, " ", 1);
		print_word(next_word);
		first_word = 0;
		delete_word(next_word);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ord_alphlong(av[1]);

	write(1, "\n", 1);
	return (0);
}
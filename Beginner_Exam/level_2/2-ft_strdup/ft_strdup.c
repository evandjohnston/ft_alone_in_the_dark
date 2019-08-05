// Passed Moulinette 2019.08.04

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char	*ft_strdup(char *src)
{
	int i = 0;
	int len = ft_strlen(src);
	char *new = malloc(sizeof(char) * (len + 1));

	while (src[i] != '\0')
	{
		new[i] = src[i];
		++i;
	}
	new[i] = '\0';

	return (new);
}
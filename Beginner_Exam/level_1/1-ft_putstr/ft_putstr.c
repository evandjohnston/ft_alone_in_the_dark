// Passed Moulinette 2019.08.04

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
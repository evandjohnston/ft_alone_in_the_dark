// Passed Moulinette 2019.09.01

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

// Passed Moulinette 2019.08.03

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

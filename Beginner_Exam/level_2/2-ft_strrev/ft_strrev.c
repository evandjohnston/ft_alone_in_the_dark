// Passed Moulinette 2019.09.01

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char	*ft_strrev(char *str)
{
	int left = 0;
	int right = ft_strlen(str) - 1;
	char swap;

	while (left < right)
	{
		swap = str[left];
		str[left] = str[right];
		str[right] = swap;
		++left;
		--right;
	}
	return (str);
}

//----------------------------------------------------------------
// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "12345";
// 	printf("%s\n", str);
// 	printf("%s\n", ft_strrev(str));
// }
// Passed Moulinette 2019.08.04

char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		++i;
	}
	s1[i] = '\0';
	return (s1);
}

//-----------------------------------------------------------
// #include <stdio.h>

// int	main(void)
// {
// 	char src[] = "Waffles";
// 	char dst[] = "Pancakes";

// 	printf("%s\n", src);
// 	printf("%s\n", dst);

// 	ft_strcpy(dst, src);

// 	printf("After copying: %s\n", dst);
// }
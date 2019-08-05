// Passed Moulinette 2019.08.03

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(reject, s[i]) != 0)
			break;
		++i;
	}
	return (i);
}

//---------------------------------------------------------------
// #include <stdio.h>
// int	main(void)
// {
// 	char haystack[] = "This is a test string";
// 	char accept[] = "tga";

// 	printf("%zu\n", ft_strcspn(haystack, accept));
// }
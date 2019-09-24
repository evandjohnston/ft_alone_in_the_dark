#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i;

	while (*s1 != '\0')
	{
		i = 0;
		while (s2[i] != '\0')
		{
			if (s2[i] == *s1)
				return ((char *)s1);
			++i;
		}
		++s1;
	}
	return (0);
}

#ifdef TEST

#include <stdio.h>

int	main(void)
{
	printf("real: %s\n", strpbrk("This is a test string\n", "g"));
	printf("test: %s\n", ft_strpbrk("This is a test string\n", "g"));
}
#endif
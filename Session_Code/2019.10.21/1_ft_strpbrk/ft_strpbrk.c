char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i1 = 0;
	int i2;

	while (s1[i1] != '\0')
	{
		i2 = 0;
		while (s2[i2] != '\0')
		{
			if (s2[i2] == s1[i1])
				return ((char *)&s1[i1]);
			i2++;
		}
		i1++;
	}
	return (0);
}

#ifdef TEST
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strpbrk("sad", "w"));
}

#endif
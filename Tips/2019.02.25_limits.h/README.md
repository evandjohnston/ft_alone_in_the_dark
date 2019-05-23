# limits.h

When writing any code that uses integers, you should always test the smallest possible value, the biggest possible value, 1, 0, and -1. Instead of trying to memorize the minimum and maximum values, just include limits.h and use its macros, INT_MIN and INT_MAX!

Here's an example of using INT_MIN and INT_MAX in a test main for ft_itoa():

```c
#include <string.h>
#include <stdlib.h>

int		ft_numdigits(long n, int base)
{
	int		len;

	if (n == 0)
		return (1);
	len = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numdigits(n, 10);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[0] = (n < 0) ? '-' : '0';
	while (n != 0)
	{
		str[--len] = (n % 10) * ((n < 0) ? -1 : 1) + '0';
		n /= 10;
	}
	return (str);
}

//---testing code below this line---
#include <limits.h>
#include <stdio.h>
int		main(void)
{
	printf("minimum integer value: %s\n", ft_itoa(INT_MIN));
	printf("-118: %s\n", ft_itoa(-118));
	printf("-1: %s\n", ft_itoa(-1));
	printf("0: %s\n", ft_itoa(0));
	printf("1: %s\n", ft_itoa(1));
	printf("890742: %s\n", ft_itoa(890742));
	printf("maximum integer value: %s\n", ft_itoa(INT_MAX));
}
```
int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		++i;
	return (i);
}

#ifdef TEST

#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	write(1, "a", 1);
	return (0);
}
#endif

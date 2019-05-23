#include <stdio.h>
#include <ctype.h>

int		main(void)
{
	int i = -1;
	while (++i < 1000)
	{
		if (isprint(i))
			printf("%d ", i);
	}
	return (0);
}
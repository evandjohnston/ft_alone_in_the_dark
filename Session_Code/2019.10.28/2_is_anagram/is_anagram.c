int	is_anagram(char *a, char *b)
{
	int arr[127] = {0};
	int i = 0;

	while (a[i] != '\0')
	{
		arr[(int)a[i]] += 1;
		++i;
	}

	i = 0;
	while (b[i] != '\0')
	{
		arr[(int)b[i]] -= 1;
		++i;
	}

	i = 0;
	while (i < 127)
	{
		if (arr[i] != 0)
			return (-1);
		++i;
	}
	return (1);
}

#ifdef TEST
#include <stdio.h>

int	main(void)
{
	char a[] = "nnnn";
	char b[] = "n";

	printf("%d\n", is_anagram(a, b));

	return (0);
}

#endif
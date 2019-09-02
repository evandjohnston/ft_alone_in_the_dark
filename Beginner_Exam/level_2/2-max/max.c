// Passed Moulinette 2019.09.01

int		max(int* tab, unsigned int len)
{
	if (len == 0)
		return (0);

	int max = tab[0];
	unsigned int i = 1;

	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		++i;
	}
	return (max);
}

//-------------------------------------------------
// #include <stdio.h>
// int main(void)
// {
// 	int tab[] = { -10, -123, -10, -12, -8, 2 };
// 	printf("%d\n", max( tab, sizeof(tab)/sizeof(*tab) ) );
// }
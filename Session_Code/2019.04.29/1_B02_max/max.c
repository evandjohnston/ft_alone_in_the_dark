#include <stdio.h> //DELETE LATER!!!

int max(int* tab, unsigned int len)
{
	unsigned int i = 0;
	int hold = 0;

	if (len == 0)
		return (0);

	if (len > 0)
		hold = tab[i];

	// if (len == 1)
	// 	return (tab[i]);

	while (i < len)
	{
		if (tab[i] > hold)
			hold = tab[i];
		i++;
	}

	return (hold);
}

int		main()
{
	int tab[] = {4};
	int len = 1;

	printf("%i\n", max(tab, len));
	return (0);

}
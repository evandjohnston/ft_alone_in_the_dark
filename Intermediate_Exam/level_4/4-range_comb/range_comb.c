// Passed Moulinette 2019.09.01

// This code was heavily influenced by dfonarev's solution (github.com/ruv1nce)

#include <stdlib.h>
#include <string.h>

int		factorial(int n)
{
	int out = n;
	while (--n > 1)
		out *= n;
	return (out);
}

void	permute(int **tab, int *avail, int *soln_buf, int n, int soln_i, int *tab_i)
{
	int i = -1;
	if (soln_i == n)
		memcpy(tab[++(*tab_i)], soln_buf, n * sizeof(int));
	else
	{
		while (++i < n)
		{
			if (avail[i] == 1)
			{
				soln_buf[soln_i] = i;
				avail[i] = 0;
				permute(tab, avail, soln_buf, n, soln_i + 1, tab_i);
				avail[i] = 1;
			}
		}
	}
}

int		**range_comb(int n)
{
	if (n <= 0)
		return (0);

	int i = -1;
	int soln_buf[n];
	int permutations = factorial(n);
	int avail[n];
	while (++i < n)
		avail[i] = 1;

	int **tab = malloc(sizeof(*tab) * (permutations + 1));
	tab[permutations] = 0;

	i = -1;
	while (++i < permutations)
		tab[i] = malloc(sizeof(**tab) * n);

	int tab_i = -1;
	permute(tab, avail, soln_buf, n, 0, &tab_i);
	return (tab);
}

#ifdef TEST		// To enable this block of code, compile with `-D TEST`
#include <stdio.h>
int	main(void)
{
	int n = 5;
	int **arr = range_comb(n);
	int i = -1;
	int j;
	int size = factorial(n);
	while (++i < size)
	{
		j = -1;
		while (++j < n)
			printf("%d, ", arr[i][j]);
		printf("\n");
	}
}
#endif
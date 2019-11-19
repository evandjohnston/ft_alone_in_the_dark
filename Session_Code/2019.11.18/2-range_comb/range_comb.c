#include <string.h>
#include <stdlib.h>

int		factorial(int n)
{
	int output = n;
	while (--n > 1)
		output *= n;
	return (output);
}

void	permute(int **tab, int *avail, int *soln, int n, int subarr_i, int *superarr_i)
{
	int i = -1;
	if (subarr_i == n)
		memcpy(tab[++(*superarr_i)], soln, n * sizeof(int));
	else
		while (++i < n)
		{
			if (avail[i] == 1)
			{
				soln[subarr_i] = i;
				avail[i] = 0;
				permute(tab, avail, soln, n, subarr_i + 1, superarr_i);
				avail[i] = 1;
			}
		}
}

int		**range_comb(int n)
{
	int	permutations = factorial(n);
	int i = -1;
	int soln[n];
	int available[n];
	while (++i < n)
		available[i] = 1;

	int **tab = malloc(sizeof(*tab) * (permutations + 1));
	tab[permutations] = 0;

	i = -1;
	while (++i < permutations)
		tab[i] = malloc(sizeof(**tab) * n);

	int superarr_idx = -1;
	permute(tab, available, soln, n, 0, &superarr_idx);
	return (tab);
}

#ifdef TEST
#include <stdio.h>

int	main(void)
{
	int n = 4;
	int **arr = range_comb(n);

	int i = 0;
	while (arr[i])
	{
		for (int j = 0; j < n; ++j)
			printf("%d, ", arr[i][j]);
		printf("\n");
		++i;
	}
}
#endif

#ifdef FACTORIAL
2! == 2 * 1
3! == 3 * 2 * 1
4! == 4 * 3 * 2 * 1
#endif
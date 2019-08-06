#include <stdlib.h>
#include <string.h>

int	factorial(int n)
{
	int out = n;
	while (--n > 1)
		out = out * n;
	return (out);
}

void	permute(int **tab, int *avail, int *soln, int n, int cur, int *soln_i)
{
	if (cur == n)
	{
		//write solution
		++(*soln_i);
		memcpy(tab[*soln_i], soln, sizeof(int) * n);
	}
	else
	{
		int i = -1;
		while (++i < n)
		{
			if (avail[i] == 1)
			{
				avail[i] = 0;
				soln[cur] = i;
				permute(tab, avail, soln, n, cur + 1, soln_i);
				avail[i] = 1;
			}
		}
	}
}

int    **range_comb(int n)
{
	if (n <= 0)
		return (0);

	int soln[n];
	int permutations = factorial(n);
	int avail[n];
	int **tab = malloc(sizeof(*tab) * (permutations + 1));
	tab[permutations] = 0;

	int i = 0;
	while (i < permutations)
	{
		tab[i] = malloc(sizeof(**tab) * (n));
		++i;
	}
	// tab[i][n] = 0;

	i = -1;
	while (++i < n)
		avail[i] = 1;

	i = -1;
	permute(tab, avail, soln, n, 0, &i);
	return (tab);
}

#if 1
#include <stdio.h>
int main(void)
{
	int n = 4;
	int **tab = range_comb(n);

	int array = -1;
	int num;
	while (tab[++array] != 0)
	{
		num = -1;
		printf("{");
		while (++num < n)
			printf("%d, ", tab[array][num]);
		printf("}");
		printf("\n");
	}

	// printf("5! = %d\n", factorial(5));
}

#endif
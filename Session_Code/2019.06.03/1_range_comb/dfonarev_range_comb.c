//#include <stdio.h>
#include <stdlib.h>

static int	count;

int		fact(int n)
{
	int fact = n;

	while (--n)
		fact *= n;
	return (fact);
}

void	permute(int **tab, int *sol, int *dp, int n, int pos)
{
	int	num, i;

	/* save solution to tab upon going beyond range [0 - n-1] */
	if (pos == n)
	{
		i = -1;
		while (++i < n)
			tab[count][i] = sol[i];
		/* increment tab counter */
		count++;
	}
	else
	{
		/* iterate through integers from 0 to n-1 */
		num = -1;
		while (++num < n)
		{
			/* if num is absent from current solution, add it to sol and mark
			 * this fact in dp, then iterate through sol positions with recursion */
			if (!dp[num])
			{
				sol[pos] = num;
				dp[num] = 1;
				permute(tab, sol, dp, n, pos + 1);
				/* after finding solution, unmark num index in dp (backtrack) */
				dp[num] = 0;
			}
		}

	}
}

int		**range_comb(int n)
{
	int	**tab;
	int	sol[n];
	int	dp[n];
	int combs;
	int	i;
	
	if (n < 1)
		return (0);
	i = -1;
	while (++i < n)
		dp[i] = 0;
	combs = fact(n);
	tab = malloc(sizeof(*tab) * (combs + 1));
	/* NULL-terminate array */
	tab[combs] = 0;
	i = -1;
	while (++i < combs)
		tab[i] = malloc(sizeof(**tab) * n);
	permute(tab, sol, dp, n, 0);
	return (tab);
}

/*
int main(int argc, char **argv)
{
	int	**tab;
	int	n, i;
	if (argc == 2)
	{
		n = atoi(argv[1]);
		tab = range_comb(n);
		while (*tab)
		{
			i = -1;
			while (++i < n)
				printf("%i ", (*tab)[i]);
			printf("\n");
			tab++;
		}
	}
}
*/
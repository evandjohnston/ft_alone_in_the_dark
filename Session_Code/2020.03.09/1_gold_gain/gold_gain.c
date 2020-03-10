int	max_three(int a, int b, int c)
{
	if (a > b)
		return ((a > c) ? a : c);
	else
		return ((b > c) ? b : c);
}

int	gold_gain(int **mine, int n)
{
	if (n = 1)
		return (mine[0][0])

	int max = -1;

	for (col = 1; col < n; col++)
	{
		for (row = 0; row < n; row++)
		{
			max_three(
				((row > 0) ? (mine[row - 1][col - 1]) : (0)),
				mine[row][col - 1],
				((row <= n) ? mine[row + 1][col - 1] : (0))
				);
			if (col == n - 1)
				max = max_three(max, mine[row][col], -1);
		}
	}
	return (max);
}
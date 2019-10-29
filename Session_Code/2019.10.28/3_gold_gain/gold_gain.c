int	max_three(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	return (c);
}

int	gold_gain(int **mine, int n)
{
	int row = 0;
	int col = 1;
	int max = 0;

	while (col < n)
	{
		row = 0;
		while (row < n)
		{
			mine[row][col] += max_three(
					( (row > 0) ? (mine[row - 1][col - 1]) : (0) ),
					mine[row][col - 1],
					( (row < n - 1) ? (mine[row + 1][col - 1]) : (0) )
				);
			if (mine[row][col] > max)
				max = mine[row][col];
			++row;
		}
		++col;
	}
	return (max);
}

#ifdef TEST
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int r0[] = {1, 3, 1, 1};
	int r1[] = {2, 2, 4, 1};
	int r2[] = {5, 0, 2, 1};
	int r3[] = {0, 6, 1, 2};
	int n = 4;

	int **mine = malloc(sizeof(int *) * n);
	for (int i = 0; i < n; ++i)
	{
		mine[i] = malloc(sizeof(int) * n);
//		for (int j = 0; j < n; ++j)
//			mine[i][j] = arr[i][j];
	}
	for (int j = 0; j < n; ++j)
		mine[0][j] = r0[j];
	for (int j = 0; j < n; ++j)
		mine[1][j] = r1[j];
	for (int j = 0; j < n; ++j)
		mine[2][j] = r2[j];
	for (int j = 0; j < n; ++j)
		mine[3][j] = r3[j];

	printf("%d\n", gold_gain(mine, n));
}
#endif
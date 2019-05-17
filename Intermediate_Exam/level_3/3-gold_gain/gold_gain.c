int	max_three(int a, int b, int c)
{
	if (a > b)
		return ((a > c) ? a : c);
	else
		return ((b > c) ? b : c);
}

int	gold_gain(int **mine, int n)
{
	int row;
	int col = 1;
	int max = 0;

	while (col < n)
	{
		row = 0;
		while (row < n)
		{
			mine[row][col] += max_three(
					((row > 0) ? mine[row - 1][col - 1] : 0),
					mine[row][col - 1],
					((row < n - 1) ? mine[row + 1][col - 1] : 0)
				);
			if (col == n - 1 && max < mine[row][col])
				max = mine[row][col];
			row++;
		}
		col++;
	}
	return (max);
}

//-------------------------------------------------------
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	// int mine[3][3] = {
// 	// 				  { 1, 0, 0 },
// 	// 				  { 0, 3, 4 },
// 	// 				  { 0, 0, 0 }
// 	// 				};
// 	// int n = sizeof(mine) / sizeof(mine[0]);


// 	// int n = 4;
// 	// int **mine = malloc(sizeof(int *) * n);
// 	// int i = 0;
// 	// while (i < n)
// 	// {
// 	// 	mine[i] = malloc(sizeof(int) * n);
// 	// 	++i;
// 	// }
// 	// mine[0][0] = 1;
// 	// mine[0][1] = 3;
// 	// mine[0][2] = 1;
// 	// mine[0][3] = 5;
// 	// mine[1][0] = 2;
// 	// mine[1][1] = 2;
// 	// mine[1][2] = 4;
// 	// mine[1][3] = 1;
// 	// mine[2][0] = 5;
// 	// mine[2][1] = 0;
// 	// mine[2][2] = 2;
// 	// mine[2][3] = 3;
// 	// mine[3][0] = 0;
// 	// mine[3][1] = 6;
// 	// mine[3][2] = 1;
// 	// mine[3][3] = 2;

// 	int n = 3;
// 	int **mine = malloc(sizeof(int *) * n);
// 	int i = 0;
// 	while (i < n)
// 	{
// 		mine[i] = malloc(sizeof(int) * n);
// 		++i;
// 	}
// 	mine[0][0] = 1;
// 	mine[0][1] = 2;
// 	mine[0][2] = 3;
// 	mine[1][0] = 3;
// 	mine[1][1] = 4;
// 	mine[1][2] = 8;
// 	mine[2][0] = 9;
// 	mine[2][1] = 6;
// 	mine[2][2] = 7;

// 	printf("%d\n", gold_gain(mine, n));
// }
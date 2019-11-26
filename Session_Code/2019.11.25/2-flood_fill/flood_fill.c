typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

void	recur(char **tab, t_point size, int col, int row, char to_fill)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x \
		|| tab[row][col] != to_fill)
		return;

	tab[row][col] = 'F';
	recur(tab, size, col - 1, row, to_fill);
	recur(tab, size, col + 1, row, to_fill);
	recur(tab, size, col, row - 1, to_fill);
	recur(tab, size, col, row + 1, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (begin.y < 0 || begin.x < 0 || begin.y >= size.y || begin.x >= size.x)
		return;
	char at_start = tab[begin.y][begin.x];
	recur(tab, size, begin.x, begin.y, at_start);
}


#ifdef TEST
#include <stdlib.h>
#include <stdio.h>
// #include "flood_fill.h"

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10100001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {4, 5};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

#endif
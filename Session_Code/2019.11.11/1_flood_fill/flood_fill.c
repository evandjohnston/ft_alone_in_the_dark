typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

void	recur(char **tab, t_point size, t_point begin, char to_replace)
{
	if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y \
		|| tab[begin.y][begin.x] != to_replace)
		return;

	tab[begin.y][begin.x] = 'F';

	// t_point cur = {begin.x, begin.y - 1};
	recur(tab, size, (t_point){begin.x, begin.y - 1}, to_replace);
	recur(tab, size, (t_point){begin.x, begin.y + 1}, to_replace);
	recur(tab, size, (t_point){begin.x - 1, begin.y}, to_replace);
	recur(tab, size, (t_point){begin.x + 1, begin.y}, to_replace);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y)
		return;
	recur(tab, size, begin, tab[begin.y][begin.x]);
}

#ifdef TEST

#include <stdlib.h>
#include <stdio.h>

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
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {2, 2};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

#endif
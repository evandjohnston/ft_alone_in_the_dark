#include <stdio.h>
#include <stdlib.h>

#include "flood_fill.c"

char	**make_area(char **zone, t_point size)
{
	int x, j, y = -1;
	char **out;

	out = malloc(sizeof(char *) * size.y);
	while (++y < size.y)
	{
		x = j = -1;
		out[y] = malloc(sizeof(char) * (size.x + 1));
		while (zone[y][++j])
			if (zone[y][j] != ' ')
				out[y][++x] = zone[y][j];
		out[y][x] = '\0';
	}
	return (out);
}

void	print_tab(char **zone, int size)
{
	int i = -1;
	while (++i < size)
		printf("%s\n", zone[i]);
}

int main(void)
{
	t_point size = {8, 5};
	t_point begin = {1, 4};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 1 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 0 0 0 0 1",
		"1 1 0 0 0 0 0 1",
	};

	char **area = make_area(zone, size);
	printf("Original:\n");
	print_tab(area, size.y);

	printf("\nResult:\n");
	flood_fill(area, size, begin);
	print_tab(area, size.y);
	return (0);
}
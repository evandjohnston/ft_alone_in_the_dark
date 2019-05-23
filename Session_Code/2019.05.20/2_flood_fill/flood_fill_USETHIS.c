#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

static size_t	ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void print_tab(char **area)
{
	int i;
	int j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 8; j++)
		{
			ft_putchar(area[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

char **make_area(char **zone)
{
	int i;
	int j;
	char **p;

	p = (char **)malloc(sizeof(char *) * 5); // # rows

	i = 0;
	while (i < 5)
	{
		p[i] = (char *)malloc(sizeof(char) * 8); // # cols
		j = 0;
		while (zone[i][j])
		{
			p[i][j] = zone[i][j];
			j++;
		}
		i++;
	}
	return (p);
}

void r(char **tab, t_point size, int x, int y, char c)
{
	if (y < 0 || x < 0 || y >= size.y || x >= size.x)
	{
		return ;
	}
	if (tab[y][x] == c)
	{
		tab[y][x] = 'F';
		r(tab, size, x, y - 1, c);			
		r(tab, size, x - 1, y, c);			
		r(tab, size, x, y + 1, c);			
		r(tab, size, x + 1, y, c);	
	}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c;
	t_point t;

	// reindex
	begin.y--;
	begin.x--;

	c = tab[begin.y][begin.x];
	r(tab, size, begin.x, begin.y, c);
}

int main(void)
{
	char **area;
	t_point size = {8, 5}; // X, Y
	t_point begin = {2, 4};
	char *zone[] = {
		"11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001"
	};

	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	//putc('\n');
	print_tab(area);
	return (0);
}
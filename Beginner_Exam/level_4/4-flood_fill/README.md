# flood_fill

## Conceptual Overview
### The Problem
We are asked to write a function that takes arguments of a 2-dimensional array of chars, and two coordinate pairs representing the dimensions of the array and the starting point in the array, respectively. The function replaces the starting character and all "connected" characters with 'F', where connected characters are those that have the same value as the starting character and are one space above, below, to the left, or to the right of the starting character.

<details>
	<summary>Full Subject</summary>

```
	Assignment name  : flood_fill
	Expected files   : *.c, *.h
	Allowed functions: -
	--------------------------------------------------------------------------------

	Write a function that takes a char ** as a 2-dimensional array of char, a 
	t_point as the dimensions of this array and a t_point as the starting point.

	Starting from the given 'begin' t_point, this function fills an entire zone 
	by replacing characters inside with the character 'F'. A zone is an group of 
	the same character delimitated horizontally and vertically by other characters
	or the array boundry.

	The flood_fill function won't fill diagonally.

	The flood_fill function will be prototyped like this:
	  void  flood_fill(char **tab, t_point size, t_point begin);

	The t_point structure is prototyped like this:

	  typedef struct  s_point
	  {
	    int           x;
	    int           y;
	  }               t_point;

	Example:

	$> cat test_main.c
	#include "test_functions.h"
	#include "flood_fill.h"

	int main(void)
	{
		char **area;
		t_point size = {8, 5};
		t_point begin = {2, 2};
		char *zone[] = {
			"1 1 1 1 1 1 1 1",
			"1 0 0 0 1 0 0 1",
			"1 0 0 1 0 0 0 1",
			"1 0 1 1 0 0 0 1",
			"1 1 1 0 0 0 0 1",
		}

		area = make_area(zone);
		print_tab(area);
		flood_fill(area, size, begin);
		putc('\n');
		print_tab(area);
		return (0);
	}

	$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill; ./flood_fill
	1 1 1 1 1 1 1 1
	1 0 0 0 1 0 0 1
	1 0 0 1 0 0 0 1
	1 0 1 0 0 0 0 1
	1 1 0 0 0 0 0 0

	1 1 1 1 1 1 1 1
	1 F F F 1 0 0 1
	1 F F 1 0 0 0 1
	1 F 1 0 0 0 0 1
	1 1 0 0 0 0 0 0
	$> 
```
</details>

### References
* [Subject File (English)](subject.en.txt)
* [flood_fill.c](flood_fill.c)

### Approach

Save the value of the character at the starting location. For each location beginning with the starting position, check if the current location is in-bounds and if the character at the current location matches the character originally at the starting location. If so, change the character at the current location to 'F' and repeat with the locations one row above, one row below, one column to the left, and one column to the right.

### Code
```C
// This code is heavily influenced by @jochang's solution: github.com/MagicHatJo

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
```

### Test Main
```C
#include <stdio.h>
#include <stdlib.h>

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
```
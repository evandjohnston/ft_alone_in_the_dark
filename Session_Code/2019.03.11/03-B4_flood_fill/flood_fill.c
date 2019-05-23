/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 17:35:48 by csinglet          #+#    #+#             */
/*   Updated: 2019/03/09 17:35:49 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

char c = '\0';

void			flood_fill(char **tab, t_point size, t_point begin)
{
	if (c == '\0')
	{
		c = tab[begin.y][begin.x];
		// begin.x--;
		// begin.y--;
	}

	t_point		right = {begin.x + 1, begin.y};
	t_point		left = {begin.x - 1, begin.y};
	t_point		up = {begin.x, begin.y - 1};
	t_point		down = {begin.x, begin.y + 1};

	if (tab[begin.y][begin.x] == c)
	{
		tab[begin.y][begin.x] = 'F';
		if (right.x < size.x)
			flood_fill(tab, size, right);
		if (left.x >= 0)
			flood_fill(tab, size, left);
		if (up.y >= 0)
			flood_fill(tab, size, up);
		if (down.y < size.y)
			flood_fill(tab, size, down);
	}
}
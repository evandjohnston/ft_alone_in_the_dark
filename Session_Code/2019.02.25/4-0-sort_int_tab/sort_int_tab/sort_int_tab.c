/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:01:19 by exam              #+#    #+#             */
/*   Updated: 2019/02/25 16:13:30 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	greater(int a, int b)
{
	if (a == b)
		return (a);
	if (a > b)
		return(a);
	else
		return(b);
}

int sorted(int *tab, unsigned int size)
{
	unsigned int i = 1;
	while(i < size)
	{
		if(tab[i - 1] > tab[i])
			return(0);
		i++;
	}
	return(1);
}

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int tmp;
	while (!sorted(tab, size))
	{
		i = 0;
		while(i < size - 1)
		{
			if(tab[i] == greater(tab[i], tab[i + 1]))
			{
				tmp = greater(tab[i], tab[i + 1]);
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
}

#include <stdio.h>

void put_tab(int *tab, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("[%d] ", tab[i]);
		i++;
	}
	printf("\n");
}

int main(void)
{
	int tab1[1] = {4}; // has a duplicate ("double" in subject)
	int tab2[5] = {2, 5, -7, 3, 4}; // has a negative that would be max if unsigned
	int tab3[5] = {0, 0, 0, 0, 0}; // blank array

	// what other cases should I test?

	sort_int_tab(tab1, 1);
	put_tab(tab1, 1);
	sort_int_tab(tab2, 4);
	put_tab(tab2, 5);
	sort_int_tab(tab3, 5);
	put_tab(tab3, 5);

	return (0);
}

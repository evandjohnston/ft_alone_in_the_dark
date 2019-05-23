/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:13:38 by exam              #+#    #+#             */
/*   Updated: 2019/04/30 10:35:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int ft_isaletter(char b)
{
	if ((b >= 33 && b <= 90) || (b >= 97 && b <= 122))
		return(1);
	else
		return(0);
}

int main(int ac, char **ag)
{
	int i = 0;
	int j = 0;
	int was = 0;
	int skip = 0;

	char word[50];

	if (ac == 2)
	{
		while (ag[1][i])
		{
			if (ft_isaletter(ag[1][i]) == 1)
			{
				if (skip == 1 && j > 0)
				{
					j = 0;
					while (word[j])
					{
						word[j] = '\0';
						j++;
					}
					j = 0;
				}
				word[j] = ag[1][i];
				i++;
				j++;
				was++;	
				skip = 0;	
			}
			else 
			{
				skip = 1;
				i++;
			}
		}
		if (was > 1)	
			ft_putstr(word);
	}
	ft_putchar('\n');
	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:05:55 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/30 20:46:16 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



int		tab_check(int val, int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (val == tab[i])
			return (0);
		i++;
	}
	return (1);
}

void	print_it(int *tab, int size)
{
	int i;
	i = 0;
	while (i < size)
	{
		ft_putnbr (tab[i++]);
		ft_putchar(32);
	}
}

int		range_finder(t_stack *a, int val)
{
	int *ntab;
	int i;
	int j;
	int cmin;

	ntab = (int *)malloc(sizeof(int) * a->size);
	i = -1;
	while (++i <= a->size / 10 + 1)
	{
		j = -1;
		cmin = 2147483647;
		while (++j < a->size)
		{
			if (tab_check(a->tab[j], ntab, i) && a->tab[j] < cmin)
				cmin = a->tab[j];
		}
		ntab[i] = cmin;
	}
	i = -1;
	j = 0;
	while (++i <= a->size / 10 + 1)
		if (val == ntab[i])
			j = 1;
	free(ntab);
	return (j);
}

int		shortest_path(t_stack *a)
{
	int i;
	int j;

	i = 0;
	j = a->size - 1;
	while (range_finder(a, a->tab[i]) == 0)
		i++;
	while (range_finder(a, a->tab[j]) == 0)
		j--;
	j = a->size - 1 - j;
	if (i < j)
		return (1);
	return (0);
}

int		shortest_min(t_stack *a)
{
	int min;
	int i;
	int j;

	min = find_min(a, 1);
	i = 0;
	j = a->size - 1;
	while (a->tab[i] != min)
		i++;
	while (a->tab[j] != min)
		j--;
	j = a->size - 1 - j;
	if (i < j)
		return (1);
	return (0);
}
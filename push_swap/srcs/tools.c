/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:05:55 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/29 23:34:53 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		chk_da_sort(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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

int		find_median(t_stack *a, int len)
{
	int *ntab;
	int i;
	int j;
	int cmin;

	ntab = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		j = 0;
		cmin = 2147483647;
		while (j < len)
		{
			if (tab_check(a->tab[j], ntab, i) && a->tab[j] < cmin)
				cmin = a->tab[j];
			j++;
		}
		ntab[i] = cmin;
		i++;
	}
	i = ntab[len / 2];
	free(ntab);
	return (i);
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

int		ten_per(t_stack *a, int val)
{
	int *ntab;
	int i;
	int j;
	int cmin;

	ntab = (int *)malloc(sizeof(int) * a->size);
	i = -1;
	while (++i < a->size)
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
	while (++i <= a->size / 3)
		if (val == ntab[i])
			j = 1;
	//print_it(ntab, a->size);
	free(ntab);
	return (j);
}
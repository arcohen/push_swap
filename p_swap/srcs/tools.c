/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:05:55 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/04 20:39:07 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_min(t_stack *stk, int max)
{
	int i;
	int ret;

	i = 0;
	while (i < stk->size)
	{
		if (max == 0 && (i == 0 || stk->tab[i] < ret))
			ret = stk->tab[i];
		else if (max == 1 && (i == 0 || stk->tab[i] > ret))
			ret = stk->tab[i];
		i++;
	}
	return (ret);
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

int		range_finder(t_stack *a, int val, int *srt_tab, int del)
{
	int i;

	i = 0;
	while (i <= a->size / 10 + 1)
	{
		if (val == srt_tab[i])
		{
			while (del && i + 1 < a->size)
			{
				srt_tab[i] = srt_tab[i + 1];
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int		shortest_path(t_stack *a, int *srt_tab)
{
	int i;
	int j;

	i = 0;
	j = a->size - 1;
	while (range_finder(a, a->tab[i], srt_tab, 0) == 0)
		i++;
	while (range_finder(a, a->tab[j], srt_tab, 0) == 0)
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

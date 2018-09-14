/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:15:13 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/11 17:36:24 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->size == 2)
		swap(a);
	else if (a->size == 3)
	{
		if (a->tab[0] < a->tab[1] && a->tab[1] < a->tab[2])
			return ;
		if (a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2])
		{
			rotate(a);
			if (a->tab[1] < a->tab[0])
				swap(a);
		}
		else if (a->tab[1] > a->tab[0] && a->tab[1] > a->tab[2])
		{
			r_rotate(a);
			if (a->tab[1] < a->tab[0])
				swap(a);
		}
		else
			swap(a);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->tab[0] == find_min(a, 0))
			push(b, a);
		else if (a->tab[1] == find_min(a, 0))
			swap(a);
		else if (a->tab[2] == find_min(a, 0))
			rotate(a);
		else
			r_rotate(a);
	}
	sort_three(a);
	while (b->size > 0)
		push(a, b);
}

void	rot_it(t_stack *b, int *revs, int way)
{
	while (b->tab[0] != find_min(b, 1))
	{
		if (way)
		{
			rotate(b);
			(*revs)++;
		}
		else
		{
			if (revs == 0)
				break ;
			r_rotate(b);
			(*revs)--;
		}
	}
}

void	pass_back(t_stack *a, t_stack *b)
{
	int revs;

	revs = 0;
	while (b->size)
	{
		if (b->tab[0] == find_min(b, 1))
			push(a, b);
		else if (revs && b->tab[0] != find_min(b, 1) && !shortest_min(b))
			rot_it(b, &revs, 0);
		else
			rot_it(b, &revs, 1);
	}
}

void	range_pass(t_stack *a, t_stack *b, int *srt_tab)
{
	while (a->size)
	{
		if (range_finder(a, a->tab[0], srt_tab, 1))
			push(b, a);
		else if (shortest_path(a, srt_tab))
			rotate(a);
		else
			r_rotate(a);
		if (b->size > 1 && b->tab[0] < b->tab[1])
			swap(b);
	}
	pass_back(a, b);
}

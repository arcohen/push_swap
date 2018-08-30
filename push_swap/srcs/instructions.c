/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:15:13 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/30 21:19:10 by arcohen          ###   ########.fr       */
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

void	sort_three(t_stack *a)
{
	if (a->size == 2)
		swap(a);
	else if (a->size == 3)
	{
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

void	print_stacks(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	ft_putstr("\na    b\n");
	while (i < a->size || i < b->size)
	{
		if (a->size > i)
		{
			ft_putnbr(a->tab[i]);
		}
		else
			ft_putstr("  ");
		ft_putstr(" -- ");
		if (b->size > i)
			ft_putnbr(b->tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar(10);
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
		//print_stacks(a, b);
		if (b->tab[0] == find_min(b, 1))
			push(a, b);
		else if (revs && b->tab[0] != find_min(b, 1) && !shortest_min(b))
			rot_it(b, &revs, 0);
		else
			rot_it(b, &revs, 1);
	}
}

void	range_pass(t_stack *a, t_stack *b)
{
	while (a->size)
	{
		if (range_finder(a, a->tab[0]))
			push(b, a);
		else if (shortest_path(a))
			rotate(a);
		else 
			r_rotate(a);
		if (b->size > 1 && b->tab[0] < b->tab[1])
			swap(b);
	}
	pass_back(a, b);
}

void	instructions(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		sort_five(a, b);
	else
		range_pass(a, b);
}
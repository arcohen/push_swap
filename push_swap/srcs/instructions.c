/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:15:13 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/29 23:18:49 by arcohen          ###   ########.fr       */
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

/*void	sort_it_a(t_stack *a, t_stack *b)
{
	while (a->size > 0)
	{
		if (a->tab[0] == find_min(a, 0))
			push(b, a);
		else if (a->tab[(a->size - 1) == find_min(a, fst)])
		{
			r_rotate(a);
			push(b, a);
		}
		else
			rotate(a);
	}
}*/

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
			ft_putstr(" -- ");
		}
		if (b->size > i)
			ft_putnbr(b->tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar(10);
}

void	insert_sort(t_stack *a, t_stack *b, int len)
{
	while (b->size != len)
	{
		//print_stacks(a, b);
		if (len - b->size > 1 && a->tab[0] > a->tab[1])
			swap(a);
		if (!b->size || a->tab[0] > b->tab[0])
			push(b, a);
		else
		{
			rotate(a);
			while (b->size && a->tab[a->size - 1] < b->tab[0])
				push(a, b);
			r_rotate(a);
			push(b, a);
		}
	}
	while (b->size)
		push(a, b);
}

void	pass_back(t_stack *a, t_stack *b)
{
	int revs;

	revs = 0;
	while (b->size)
	{
		print_it(b->tab, b->size);
		if (b->tab[0] == find_min(b, 1))
		{
			push(a, b);
			while (revs > 0 && b->tab[0] != find_min(b, 1))
			{
				r_rotate(b);
				revs--;
			}
		}
		else
		{
			while (b->tab[0] != find_min(b, 1))
			{
				rotate(b);
				revs++;
			}
		}
	}
}

void	per_pass(t_stack *a, t_stack *b)
{
	while (a->size)
	{
		print_it(b->tab, b->size);
		if (ten_per(a, a->tab[0]))
			push(b, a);
		else
			rotate(a);
	}
	pass_back(a, b);
}



void	instructions(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		per_pass(a, b);
		//quick_sort(a, b, a->size);
	//print_stacks(a, b);
}
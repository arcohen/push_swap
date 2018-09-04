/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:30:00 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/04 20:47:48 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	shift(t_stack *stack_x, int up)
{
	int i;

	if (up)
	{
		i = stack_x->size;
		while (--i > 0)
			stack_x->tab[i] = stack_x->tab[i - 1];
	}
	else
	{
		i = 0;
		while (i < stack_x->size - 1)
		{
			stack_x->tab[i] = stack_x->tab[i + 1];
			i++;
		}
	}
}

void	swap(t_stack *stack_x)
{
	int temp;

	if (stack_x->size > 1)
	{
		temp = stack_x->tab[0];
		stack_x->tab[0] = stack_x->tab[1];
		stack_x->tab[1] = temp;
		if (stack_x->stk == 'a')
			ft_putstr("sa\n");
		else
			ft_putstr("sb\n");
	}
}

void	push(t_stack *stack_x, t_stack *stack_y)
{
	if (stack_y->size > 0)
	{
		stack_x->size++;
		shift(stack_x, 1);
		stack_x->tab[0] = stack_y->tab[0];
		shift(stack_y, 0);
		stack_y->size--;
		if (stack_x->stk == 'a')
			ft_putstr("pa\n");
		else
			ft_putstr("pb\n");
	}
}

void	r_rotate(t_stack *stack_x)
{
	int temp;

	if (stack_x->size > 1)
	{
		temp = stack_x->tab[stack_x->size - 1];
		shift(stack_x, 1);
		stack_x->tab[0] = temp;
		if (stack_x->stk == 'a')
			ft_putstr("rra\n");
		else
			ft_putstr("rrb\n");
	}
}

void	rotate(t_stack *stack_x)
{
	int temp;

	if (stack_x->size > 1)
	{
		temp = stack_x->tab[0];
		shift(stack_x, 0);
		stack_x->tab[stack_x->size - 1] = temp;
		if (stack_x->stk == 'a')
			ft_putstr("ra\n");
		else
			ft_putstr("rb\n");
	}
}

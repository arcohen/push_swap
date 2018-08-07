/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:30:00 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/07 16:04:39 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	ft_putnbr(123);
	ft_putnbr(stack_x->size);
	ft_putnbr(456);
	if (stack_x->size > 1)
	{
		int temp;

		temp = stack_x->tab[0];
		stack_x->tab[0] = stack_x->tab[1];
		stack_x->tab[1] = temp;
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
	}
}

void	rotate(t_stack *stack_x)
{
	int temp;

	if (stack_x->size > 1)
	{
		temp = stack_x->tab[stack_x->size - 1];
		shift(stack_x, 1);
		stack_x->tab[0] = temp;
	}
}

void	r_rotate(t_stack *stack_x)
{
	int temp;

	if (stack_x->size > 1)
	{
		temp = stack_x->tab[0];
		shift(stack_x, 0);
		stack_x->tab[stack_x->size - 1] = temp;
	}
}
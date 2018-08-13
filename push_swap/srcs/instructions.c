/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:15:13 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/13 20:23:14 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void		instructions(t_stack *a, t_stack *b)
{
	while (a->size)
	{
		if (a->size > 1 && a->tab[0] > a->tab[1])
			swap(a);
		while (a->tab[a->size - 1] < a->tab[0])
			r_rotate(a);
		push(b, a);
		if (b->size > 1 && b->tab[0] < b->tab[1])
		{
			rotate(b);
			if ()
			while (b->size > 1 && b->tab[b->size - 1] < b->tab[0])
				push(a, b);
			r_rotate(b);
		}
	}
	while (b->size)
		push(a, b);
}
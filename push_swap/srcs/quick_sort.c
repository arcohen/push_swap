/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:03:53 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/29 19:44:39 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quick_sort(t_stack *a, t_stack *b, int len)
{
	int i;
	int k;
	int pivot;

	//print_stacks(a, b);
	if (chk_da_sort(a->tab, len))
		return ;
	if (len < 21)
	{
		insert_sort(a, b, len);
		return ;
	}
	pivot = find_median(a, len);
	i = 0;
	while (i++ < len)
	{
		if (a->tab[0] < pivot)
			push(b, a);
		else
			rotate(a);
	}
	if (b->size == 0)
		return ;
	i = len - b->size;
	while (i--)
		r_rotate(a);
	i = b->size;
	//print_stacks(a, b);
	while (b->size)
		push(a, b);
	quick_sort(a, b, i);
	k = i;
	while (i-- > 0)
		rotate(a);
	quick_sort(a, b, len - k);
	while (k--)
		r_rotate(a);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:28:57 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/04 20:46:16 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->tab);
	free(stack_b->tab);
	free(stack_a);
	free(stack_b);
}

int		check_if_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	if (stack_b->size != 0)
		return (0);
	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->tab[i] > stack_a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		*sort_tab(t_stack *a)
{
	int *ntab;
	int cmin;
	int i;
	int j;

	i = 0;
	ntab = (int *)malloc(sizeof(int) * a->size);
	while (i < a->size)
	{
		j = -1;
		cmin = 2147483647;
		while (++j < a->size)
			if (tab_check(a->tab[j], ntab, i) && a->tab[j] < cmin)
				cmin = a->tab[j];
		ntab[i] = cmin;
		i++;
	}
	return (ntab);
}

void	instructions(t_stack *a, t_stack *b, int *srt_tab)
{
	if (a->size <= 5)
		sort_five(a, b);
	else
		range_pass(a, b, srt_tab);
}

int		main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*srt_tab;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (ac < 2)
		return (0);
	if (!check_digits(av) || !make_stack(stack_a, stack_b, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	srt_tab = sort_tab(stack_a);
	if (ac > 1 && !check_if_sorted(stack_a, stack_b))
		instructions(stack_a, stack_b, srt_tab);
	free_all(stack_a, stack_b);
	return (0);
}

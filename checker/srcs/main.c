/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:46:54 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/04 20:53:05 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

int		main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (ac < 2)
		return (0);
	if (!check_digits(av) || !make_stack(stack_a, stack_b, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!instructions(stack_a, stack_b))
		ft_putstr_fd("Error\n", 2);
	else if (check_if_sorted(stack_a, stack_b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_all(stack_a, stack_b);
	return (0);
}

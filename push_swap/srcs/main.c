/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:28:57 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/27 15:19:30 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*int		minit(t_stack *a, int *srted, int k)
{
	int i;
	int	ret;

	i = 0;
	ret = a->tab[0];
	while (i < a->size)
	{
		if (a->tab[i] < ret && (k == -1 || a->tab[i] > srted[k]))
			ret = a->tab[i];
		i++;
	}
	return (ret);
}

int		*sort_it(t_stack *a, int *sorted)
{
	int i;

	i = 0;
	sorted = (int *)malloc(sizeof(int) * a->size);
	while (i < a->size)
	{
		sorted[i] = minit(a, sorted, i - 1);
		i++;
	}
}*/

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
	if (ac > 1 && !check_if_sorted(stack_a, stack_b))
		instructions(stack_a, stack_b);
	free_all(stack_a, stack_b);
	return (0);
}
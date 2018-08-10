/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 16:33:37 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/08 15:01:38 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		count_nbs(char **av)
{
	int ret;
	int i;
	int j;

	ret = 0;
	i = 1;
	while(av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 || av[i][j - 1] == ' ')
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

void	fill_stack(int *tab, char **av)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 1;
	while(av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 || av[i][j - 1] == ' ')
				tab[k++] = ft_atoi(&av[i][j]);
			j++;
		}
		i++;
	}
}

void	create_tab(t_stack *stack_a, t_stack *stack_b, char **av)
{
	int size;

	size = count_nbs(av);
	stack_a->tab = (int *)malloc(sizeof(int) * size);
	stack_a->size = size;
	stack_b->tab = (int *)malloc(sizeof(int) * size);
	stack_b->size = 0;
}

int		make_stack(t_stack *stack_a, t_stack *stack_b, char **av)
{
	create_tab(stack_a, stack_b, av);
	fill_stack(stack_a->tab, av);
	if (check_dup(stack_a->tab, stack_a->size) == 0)
	{
		free_all(stack_a, stack_b);
		return (0);
	}
	return (1);
}
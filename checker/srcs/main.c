/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:46:54 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/02 19:55:11 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (ac < 2)
		return (0);
	if (!check_digits(av) || !make_stack(stack_a, stack_b, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}

}
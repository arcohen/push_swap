/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:09:49 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/07 18:14:36 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_digits(char **argv)
{
	int i;
	int j;
	
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_atoi_long(&argv[i][j]) > INT_MAX || ft_atoi_long(&argv[i][j]) < INT_MIN)
				return (0);
			if ((argv[i][j] == '-' || argv[i][j] == '+') && !ft_isdigit(argv[i][j + 1]))
				return (0);
			else if (argv[i][j] == ' ' && !ft_isdigit(argv[i][j + 1]))
				return (0);
			else if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_dup(int *tab, int size)
{
	int i;
	int k;

	i = 1;
	while (i < size)
	{
		k = i - 1;
		while (k >= 0)
		{
			if (tab[i] == tab[k])
				return (0);
			k--;
		}
		i++;
	}
	return (1);
}
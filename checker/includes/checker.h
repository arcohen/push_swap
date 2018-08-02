/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:18:55 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/02 16:36:25 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"

typedef struct  s_stack
{
    int *tab;
    int size;
}               t_stack;

int		check_digits(char **argv);
int		check_dup(int *tab, int size);

# endif

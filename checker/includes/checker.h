/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:18:55 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/07 14:45:31 by arcohen          ###   ########.fr       */
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
int		make_stack(t_stack *stack_a, t_stack *stack_b, char **av);
void	swap(t_stack *stack_x);
void	push(t_stack *stack_x, t_stack *stack_y);
void	rotate(t_stack *stack_x);
void	r_rotate(t_stack *stack_x);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	r_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	free_all(t_stack *stack_a, t_stack *stack_b);
int		instructions(t_stack *stack_a, t_stack *stack_b);

# endif

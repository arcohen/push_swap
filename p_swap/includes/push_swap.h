/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:18:55 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/11 16:27:56 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"

typedef struct	s_stack
{
	int		*tab;
	int		size;
	char	stk;
}				t_stack;

int				check_digits(char **argv);
int				check_dup(int *tab, int size);
int				make_stack(t_stack *stack_a, t_stack *stack_b, char **av);
void			swap(t_stack *stack_x);
void			push(t_stack *stack_x, t_stack *stack_y);
void			rotate(t_stack *stack_x);
void			r_rotate(t_stack *stack_x);
void			instructions(t_stack *a, t_stack *b, int *srt_tab);
int				check_if_sorted(t_stack *stack_a, t_stack *stack_b);
int				chk_da_sort(int *tab, int size);
int				tab_check(int val, int *tab, int size);
int				find_median(t_stack *a, int len);
int				range_finder(t_stack *a, int val, int *srt_tab, int del);
void			print_it(int *tab, int size);
int				shortest_path(t_stack *a, int *srt_tab);
int				find_min(t_stack *stk, int max);
int				shortest_min(t_stack *a);
void			range_pass(t_stack *a, t_stack *b, int *srt_tab);
void			sort_five(t_stack *a, t_stack *b);

#endif

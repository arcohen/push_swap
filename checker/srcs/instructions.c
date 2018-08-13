/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:15:13 by arcohen           #+#    #+#             */
/*   Updated: 2018/08/13 12:29:54 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	r_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
}

int		perform_op(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(line, "ss") == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strcmp(line, "pa") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(line, "pb") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strcmp(line, "rra") == 0)
		r_rotate(stack_a);
	else if (ft_strcmp(line, "rrb") == 0)
		r_rotate(stack_b);
	else if (ft_strcmp(line, "rrr") == 0)
		r_rotate_both(stack_a, stack_b);
	else
		return (0);
	return (1);
}

/*void	print_tab(t_stack *stk)
{
	int i;

	i = 0;
	ft_putstr("size:\n");
	ft_putnbr(stk->size);
	ft_putstr("\narray:\n");
	while (i < stk->size)
	{
		ft_putnbr(stk->tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("-------\n");
}*/

int		instructions(t_stack *stack_a, t_stack *stack_b)
{
	char *line;

	while (get_next_line(0, &line) == 1)
	{
		if (perform_op(stack_a, stack_b, line) == 0)
		{
			free(line);
			return (0);
		}
		//print_tab(stack_a);
		//print_tab(stack_b);
		free(line);
	}
	return (1);
}
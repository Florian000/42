/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:50:57 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/30 13:54:41 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print == 1)
		ft_printf("ss\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print == 1)
		ft_printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print == 1)
		ft_printf("rrr\n");
}

void	rotate(t_stack **stack, int nb, void (*f)(t_stack**, int))
{
	while (nb > 0)
	{
		f(stack, 1);
		nb--;
	}
}

void	sy(t_stack **a, t_stack **b, int nb, void (*f)(t_stack**,
			t_stack**, int))
{
	while (nb > 0)
	{
		f(a, b, 1);
		nb--;
	}
}

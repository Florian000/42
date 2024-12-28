/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:50:57 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/30 12:13:08 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	sa(t_stack **stack, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (print == 1)
		ft_printf("sa\n");
}

void	ra(t_stack **stack, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print == 1)
		ft_printf("ra\n");
}

void	rra(t_stack **stack, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	second_last = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (print == 1)
		ft_printf("rra\n");
}

void	pa(t_stack **stack_s, t_stack **stack_d, int print)
{
	t_stack	*top;

	if (*stack_s == NULL)
		return ;
	top = *stack_s;
	*stack_s = top->next;
	top->next = *stack_d;
	*stack_d = top;
	if (print == 1)
		ft_printf("pa\n");
}

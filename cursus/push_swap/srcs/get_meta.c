/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:34:04 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/28 14:59:19 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->number < min->number)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->cost < cheapest->cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	init_target(t_stack *stack_s, t_stack *stack_t)
{
	int		upper;
	t_stack	*top;
	t_stack	*target;

	target = NULL;
	top = stack_t;
	while (stack_s)
	{
		upper = INT_MAX;
		target = NULL;
		stack_t = top;
		while (stack_t)
		{
			if (stack_t->number > stack_s->number && stack_t->number < upper)
			{
				upper = stack_t->number;
				target = stack_t;
			}
			stack_t = stack_t->next;
		}
		if (!target)
			target = get_min(top);
		stack_s->target = target;
		stack_s = stack_s->next;
	}
}

void	get_costs(t_stack *stack)
{
	int			cost_s;
	int			cost_t;
	const int	len_s = len_stack(stack);

	while (stack)
	{
		if (stack->median == 1)
			cost_s = stack->index;
		else if (stack->median == -1)
			cost_s = len_s - stack->index;
		if (stack->target->median == 1)
			cost_t = stack->target->index;
		else if (stack->target->median == -1)
			cost_t = len_stack(stack->target);
		if (stack->median == stack->target->median)
		{
			if (cost_s >= cost_t)
				stack->cost = cost_s;
			else
				stack->cost = cost_t;
		}
		else
			stack->cost = cost_s + cost_t;
		stack = stack->next;
	}
}

void	init_nodes(t_stack	*stack)
{
	int	len;
	int	index;

	len = len_stack(stack);
	index = 0;
	while (stack)
	{
		stack->index = index;
		if (len / 2 >= index)
			stack->median = 1;
		else
			stack->median = -1;
		stack = stack->next;
		index++;
	}
}

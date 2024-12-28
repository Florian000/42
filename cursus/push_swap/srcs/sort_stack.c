/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:01:24 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/30 13:53:07 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->number;
	middle = (*a)->next->number;
	bottom = (*a)->next->next->number;
	if (top > middle && top > bottom)
		ra(a, 1);
	else if (middle > bottom)
		rra(a, 1);
	top = (*a)->number;
	middle = (*a)->next->number;
	if (top > middle)
		sa(a, 1);
}

void	rotate_median(t_stack **a, t_stack **b, t_stack *c)
{
	const int		l_s = len_stack(*b);
	const int		l_t = len_stack(*a);

	if (c->index <= c->target->index && c->median == 1)
	{
		sy(a, b, c->index, rr);
		rotate(a, c->target->index - c->index, ra);
	}
	else if (c->index > c->target->index && c->median == 1)
	{
		sy(a, b, c->target->index, rr);
		rotate(b, c->index - c->target->index, rb);
	}
	else if (l_s - c->index <= l_t - c->target->index && c->median == -1)
	{
		sy(a, b, l_s - c->index, rrr);
		rotate(a, (l_t - c->target->index) - (l_s - c->index), rra);
	}
	else if (l_s - c->index > l_t - c->target->index && c->median == -1)
	{
		sy(a, b, l_t - c->target->index, rrr);
		rotate(b, (l_s - c->index) - (l_t - c->target->index), rrb);
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack			*c;
	const int		len_s = len_stack(*b);
	const int		len_t = len_stack(*a);

	c = get_cheapest(*b);
	if (c->median == c->target->median)
		rotate_median(a, b, c);
	else
	{
		if (c->median >= 0)
		{
			rotate(b, c->index, rb);
			rotate(a, len_t - c->target->index, rra);
		}
		else
		{
			rotate(b, len_s - c->index, rrb);
			rotate(a, c->target->index, ra);
		}
	}
	pa(b, a, 1);
}

void	sort_big(t_stack **a, t_stack **b)
{
	t_stack	*first;

	while (len_stack(*a) > 3)
		pb(a, b, 1);
	small_sort(a);
	while (*b)
	{
		init_nodes(*b);
		init_nodes(*a);
		init_target(*b, *a);
		get_costs(*b);
		push_b(a, b);
	}
	init_nodes(*a);
	first = get_min(*a);
	if (first->index <= len_stack(*a) / 2)
		while ((*a)->index != first->index)
			ra(a, 1);
	else
		while ((*a)->index != first->index)
			rra(a, 1);
}

void	ft_sort_stack(t_stack **a)
{
	t_stack	*b;

	if (!a)
		return ;
	b = NULL;
	if (len_stack(*a) == 2)
		sa(a, 1);
	else if (len_stack(*a) == 3)
		small_sort(a);
	else
		sort_big(a, &b);
	free_stack(&b);
}

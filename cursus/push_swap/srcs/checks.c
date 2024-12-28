/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:44:55 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/28 13:12:04 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_num(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
		i++;
	if (!c[i])
		return (0);
	while (c[i])
	{
		if (!(ft_isdigit(c[i])))
			return (0);
		i++;
	}
	if (!check_size(c))
		return (0);
	return (1);
}

int	check_duplicates(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack_a;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->number == checker->number)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_size(char *c)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*c == '+')
		c++;
	if (*c == '-')
	{
		sign = -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
	{
		num = num * 10 + (*c - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
		c++;
	}
	return (1);
}

int	check_sorted(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

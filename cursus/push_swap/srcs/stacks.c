/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:32:05 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/30 14:43:27 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

t_stack	*create_node(int number, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

void	push_stack(t_stack **stack, int number, int index)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = create_node(number, index);
	if (!new_node)
		return ;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}
/*
void	print_stack(t_stack *stack) 
{
	while (stack) 
	{
		ft_printf("Number: %d, Index: %d \n", stack->number, stack->index);
		stack = stack->next;
	}
}
*/

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	len_stack(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

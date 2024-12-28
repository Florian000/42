/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:38:49 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/30 16:00:02 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	free_string_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	get_stack(t_stack **stack_a, char **items)
{
	int	i;

	i = 0;
	while (items[i])
	{
		if (check_num(items[i]))
			push_stack(stack_a, ft_atoi(items[i]), i);
		else
		{
			free_stack(stack_a);
			write(STDERR_FILENO, "Error\n", 6);
			return ;
		}
		i++;
	}
}

t_stack	*get_data(int size, char **argv)
{
	t_stack	*stack_a;
	char	**items;

	stack_a = NULL;
	if (size == 2)
	{
		items = ft_split(argv[1], ' ');
		if (!items)
			return (write(STDERR_FILENO, "Error\n", 6), NULL);
		if (!items[0])
		{
			free_string_array(items);
			return (write(STDERR_FILENO, "Error\n", 6), NULL);
		}
		get_stack(&stack_a, items);
		free_string_array(items);
	}
	else
		get_stack(&stack_a, argv + 1);
	return (stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:04:34 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/30 16:02:25 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac < 2)
		return (EXIT_FAILURE);
	stack_a = get_data(ac, av);
	if (!stack_a)
		return (EXIT_FAILURE);
	if (check_duplicates(stack_a))
	{
		free_stack(&stack_a);
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	if (!check_sorted(stack_a))
		ft_sort_stack(&stack_a);
	free_stack(&stack_a);
	return (EXIT_SUCCESS);
}

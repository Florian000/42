/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:04:01 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/30 16:01:45 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

int	clean_exit(t_stack *stack_b, char *move)
{
	move = get_next_line(0, 1);
	free(move);
	if (stack_b)
		free_stack(&stack_b);
	return (1);
}

int	ft_exec_moves(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strncmp(move, "rra", 3) && ft_strlen(move) == 4)
		rra(stack_a, 0);
	else if (!ft_strncmp(move, "rrb", 3) && ft_strlen(move) == 4)
		rrb(stack_b, 0);
	else if (!ft_strncmp(move, "rrr", 3) && ft_strlen(move) == 4)
		rrr(stack_a, stack_b, 0);
	else if (!ft_strncmp(move, "ra", 2) && ft_strlen(move) == 3)
		ra(stack_a, 0);
	else if (!ft_strncmp(move, "rb", 2) && ft_strlen(move) == 3)
		rb(stack_b, 0);
	else if (!ft_strncmp(move, "pa", 2) && ft_strlen(move) == 3)
		pa(stack_b, stack_a, 0);
	else if (!ft_strncmp(move, "pb", 2) && ft_strlen(move) == 3)
		pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(move, "sa", 2) && ft_strlen(move) == 3)
		sa(stack_a, 0);
	else if (!ft_strncmp(move, "sb", 2) && ft_strlen(move) == 3)
		sb(stack_b, 0);
	else if (!ft_strncmp(move, "rr", 2) && ft_strlen(move) == 3)
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(move, "ss", 2) && ft_strlen(move) == 3)
		ss(stack_a, stack_b, 0);
	else
		return (write(STDERR_FILENO, "Error\n", 6), 1);
	return (0);
}

int	ft_moves(t_stack **stack_a)
{
	char	*move;
	int		ret;
	t_stack	*stack_b;

	stack_b = NULL;
	move = get_next_line(0, 0);
	while (move)
	{
		ret = ft_exec_moves(stack_a, &stack_b, move);
		free(move);
		if (ret == 1)
			return (clean_exit(stack_b, move));
		move = get_next_line(0, 0);
	}
	if (stack_b)
	{
		if (ret == 0)
			write(STDOUT_FILENO, "KO\n", 3);
	}
	else
		free_stack(&stack_b);
	return (free(move), 0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		ret;

	if (ac < 2)
		return (EXIT_FAILURE);
	stack_a = get_data(ac, av);
	if (!stack_a)
		return (EXIT_FAILURE);
	if (check_duplicates(stack_a))
	{
		free_stack(&stack_a);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	ret = ft_moves(&stack_a);
	if (ret == 0 && check_sorted(stack_a))
		write(STDOUT_FILENO, "OK\n", 3);
	else if (ret == 0)
	{
		write(STDOUT_FILENO, "KO\n", 3);
	}
	return (free_stack(&stack_a), EXIT_SUCCESS);
}

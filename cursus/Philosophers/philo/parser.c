/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:07:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/03/02 14:39:05 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parser(int ac, char **av, t_table *table)
{
	if (ac < 5 || ac > 6)
		return (error_handler(ARGS_WRONG), EXIT_FAILURE);
	table->n_meals = -2;
	table->n_philo = ft_atol(av[1]);
	table->t_die = ft_atol(av[2]) * 1000;
	table->t_eat = ft_atol(av[3]) * 1000;
	table->t_sleep = ft_atol(av[4]) * 1000;
	if (table->n_philo > MAX_PHILO || table->n_philo <= 0)
		return (error_handler(PHILO_WRONG), EXIT_FAILURE);
	if (table->t_die < 60 * 1000)
		return (error_handler(DIE_WRONG), EXIT_FAILURE);
	if (table->t_eat < 60 * 1000)
		return (error_handler(EAT_WRONG), EXIT_FAILURE);
	if (table->t_sleep < 60 * 1000)
		return (error_handler(SLEEP_WRONG), EXIT_FAILURE);
	if (ac == 6)
		table->n_meals = ft_atol(av[5]);
	if (table->n_meals == -1)
		return (error_handler(MEALS_WRONG), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:16:47 by fgranger          #+#    #+#             */
/*   Updated: 2024/03/02 14:38:02 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_table *table)
{
	int	i;

	i = -1;
	table->start = gettime(MILLISECOND);
	if (table->n_philo == 1)
	{
		if (safe_thread(&table->philos[0].thread_id, dinner_alone, \
		&table->philos[0], CREATE) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		while (++i < table->n_philo)
			if (safe_thread(&table->philos[i].thread_id, dinner_run, \
			&table->philos[i], CREATE) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	if (safe_thread(&table->monitor, monitor, table, CREATE) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->n_philo;
	philo->first = &forks[(philo_position + 1) % philo_nbr];
	philo->second = &forks[philo_position];
	if (philo->id == philo->table->n_philo)
	{
		philo->first = &forks[philo_position];
		philo->second = &forks[(philo_position + 1) % philo_nbr];
	}
	return (EXIT_SUCCESS);
}

static int	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->n_philo)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->last_meal = 0;
		philo->meals = 0;
		philo->is_init = false;
		if (safe_mutex(&philo->mtx_philo, INIT) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		philo->is_init = true;
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}
	return (EXIT_SUCCESS);
}

static int	init_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philo)
	{
		table->forks[i].is_init = false;
		if (safe_mutex(&table->forks[i].fork, INIT))
			return (EXIT_FAILURE);
		table->forks[i].is_init = true;
		table->forks[i].fork_id = i;
	}
	return (EXIT_SUCCESS);
}

int	init_dinner(t_table *table)
{
	table->end = false;
	table->sync = false;
	table->start = 0;
	table->n_running = 0;
	table->philos = malloc(table->n_philo * sizeof(t_philo));
	table->forks = malloc(table->n_philo * sizeof(t_fork));
	if (table->philos == NULL || table->forks == NULL)
		return (EXIT_FAILURE);
	set_init_flags(table);
	if (safe_mutex(&table->write_mutex, INIT) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	table->is_table_init = true;
	if (safe_mutex(&table->table_mutex, INIT) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	table->is_write_init = true;
	if (init_forks(table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (philo_init(table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

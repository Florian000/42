/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:56:59 by fgranger          #+#    #+#             */
/*   Updated: 2024/03/02 14:38:20 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	write_status(THINKING, philo);
	if (philo->table->n_philo % 2 != 0)
		precise_usleep(philo->table->t_eat * 0.42, philo->table);
}

void	*dinner_alone(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	increase_long(&philo->table->table_mutex, &philo->table->n_running);
	set_long(&philo->mtx_philo, &philo->last_meal, gettime(MILLISECOND));
	write_status(TAKE_FIRST_FORK, philo);
	while (!simulation_finished(philo->table))
		precise_usleep(200, philo->table);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->first->fork);
	write_status(TAKE_FIRST_FORK, philo);
	pthread_mutex_lock(&philo->second->fork);
	write_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->mtx_philo, &philo->last_meal, gettime(MILLISECOND));
	philo->meals++;
	write_status(EATING, philo);
	precise_usleep(philo->table->t_eat, philo->table);
	if (philo->table->n_meals > 0 && philo->meals == philo->table->n_meals)
		set_bool(&philo->mtx_philo, &philo->full, true);
	pthread_mutex_unlock(&philo->first->fork);
	pthread_mutex_unlock(&philo->second->fork);
}

void	*dinner_run(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	if (philo->id % 2)
		usleep(10000);
	increase_long(&philo->table->table_mutex, &philo->table->n_running);
	set_long(&philo->mtx_philo, &philo->last_meal, gettime(MILLISECOND));
	while (!simulation_finished(philo->table) && !philo->full)
	{
		eat(philo);
		write_status(SLEEPING, philo);
		precise_usleep(philo->table->t_sleep, philo->table);
		thinking(philo);
	}
	return (NULL);
}

int	dinner_start(t_table *table)
{
	int		i;

	i = -1;
	if (table->n_meals == 0)
		return (EXIT_SUCCESS);
	init_threads(table);
	i = -1;
	while (++i < table->n_philo)
		if (safe_thread(&table->philos[i].thread_id, NULL, NULL, JOIN) == 1)
			return (EXIT_FAILURE);
	set_bool(&table->table_mutex, &table->end, true);
	if (safe_thread(&table->monitor, NULL, NULL, JOIN) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:25:10 by fgranger          #+#    #+#             */
/*   Updated: 2024/03/02 14:38:58 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->mtx_philo, &philo->full))
		return (false);
	if (get_long(&philo->mtx_philo, &philo->meals) == 0)
		elapsed = gettime(MILLISECOND) - get_long(&philo->mtx_philo, \
		&philo->table->start);
	else
		elapsed = gettime(MILLISECOND) - get_long(&philo->mtx_philo, \
		&philo->last_meal);
	t_to_die = philo->table->t_die / 1000;
	if (elapsed > t_to_die)
		return (true);
	return (false);
}

void	*monitor(void *data)
{
	int			i;
	t_table		*table;

	table = (t_table *)data;
	usleep(50 * table->n_philo);
	while (!simulation_finished(table))
	{	
		i = -1;
		while (++i < table->n_philo && !simulation_finished(table))
		{
			if (philo_died(table->philos + i))
			{
				set_bool(&table->table_mutex, &table->end, true);
				write_status(DIED, table->philos + i);
			}
		}
	}
	return (NULL);
}

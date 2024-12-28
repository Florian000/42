/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:34:43 by fgranger          #+#    #+#             */
/*   Updated: 2024/03/02 14:38:12 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_init_flags(t_table *table)
{
	table->is_table_init = false;
	table->is_write_init = false;
}

void	clean(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->n_philo && table->philos[i].is_init)
		safe_mutex(&table->philos[i++].mtx_philo, DESTROY);
	i = 0;
	while (i < table->n_philo && table->forks[i].is_init)
		safe_mutex(&table->forks[i++].fork, DESTROY);
	if (table->is_write_init)
		safe_mutex(&table->write_mutex, DESTROY);
	if (table->is_table_init)
		safe_mutex(&table->table_mutex, DESTROY);
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
}

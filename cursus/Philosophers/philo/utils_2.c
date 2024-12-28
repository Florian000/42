/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:30:47 by fgranger          #+#    #+#             */
/*   Updated: 2024/03/02 14:39:33 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end));
}

long	gettime(int time_code)
{
	struct timeval	tv;

	if (handle_sys_error(gettimeofday(&tv, NULL)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (MILLISECOND == time_code)
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	else if (MICROSECOND == time_code)
		return (tv.tv_sec * 1000000 + tv.tv_usec);
	else if (SECONDS == time_code)
		return (tv.tv_sec + tv.tv_usec / 1000000);
	return (EXIT_FAILURE);
}

void	precise_usleep(long usec, t_table *table)
{
	long	start_time;
	long	end_time;

	start_time = gettime(MICROSECOND);
	end_time = start_time + usec;
	while (gettime(MICROSECOND) <= end_time && !simulation_finished(table))
	{
		usec *= 0.15;
		if (usec < 50)
			usleep(50);
		else
			usleep(usec);
	}
}

void	write_status(t_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->table->start;
	if (get_bool(&philo->mtx_philo, &philo->full))
		return ;
	safe_mutex(&philo->table->write_mutex, LOCK);
	if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
		&& !simulation_finished(philo->table))
		printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf("%-6ld %d is eating\n", elapsed, philo->id);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf("%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf("%-6ld %d is thinking\n", elapsed, philo->id);
	else if (DIED == status)
		printf("%-6ld %d died\n", elapsed, philo->id);
	safe_mutex(&philo->table->write_mutex, UNLOCK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:02:41 by fgranger          #+#    #+#             */
/*   Updated: 2024/03/02 14:38:51 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (parser(ac, av, &table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_dinner(&table) == EXIT_FAILURE)
		return (clean(&table), EXIT_FAILURE);
	if (dinner_start(&table) == EXIT_FAILURE)
		return (clean(&table), EXIT_FAILURE);
	clean(&table);
	return (EXIT_SUCCESS);
}

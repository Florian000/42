/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:36:45 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/17 17:13:28 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Minitalk.h"

void	send_message(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 3 && atoi(av[1]) > 0)
	{
		while (av[2][i])
		{
			send_message(atoi(av[1]), av[2][i]);
			i++;
		}
	}
	else
		return (ft_printf("Error\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

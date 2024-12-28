/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:27:40 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/30 13:12:30 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int	ft_atoi(char *nb)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nb[i] <= ' ')
		i++;
	while (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			sign *= -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
		result = result * 10 + nb[i++] - 48;
	return (result * sign);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	ft_doop(ft_atoi(av[1]), av[2], ft_atoi(av[3]));
	return (0);
}

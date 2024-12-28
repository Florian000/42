/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:17:35 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/21 19:20:09 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"

int	main(int ac, char **av)
{
	int		n;
	char	*grid[2];

	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	n = ft_check_input(av[1]);
	if (n > 0)
	{
		ft_clean_input(av[1], n, grid);
		ft_rush01(grid, n);
		ft_free(grid);
	}
	else
		ft_putstr("Error\n");
	return (0);
}

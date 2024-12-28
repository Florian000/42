/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:18:18 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/21 14:23:00 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_display(char **grid, int n, int *check)
{
	int	i;
	int	col;

	i = 0;
	col = 1;
	while (grid[1][i])
	{
		ft_putchar(grid[1][i]);
		if (col != n)
			ft_putchar(' ');
		else
		{
			col = 0;
			ft_putchar('\n');
		}
		col++;
		i++;
	}
	*check = 1;
}

void	ft_backtrack(char **grid, int pos, int n, int *check)
{
	if (pos == n * n)
	{
		ft_display(grid, n, &(*check));
		return ;
	}
	grid[1][pos] = '1';
	while (grid[1][pos] <= n + '0')
	{
		if (ft_check_tower(grid, pos, n))
			ft_backtrack(grid, pos + 1, n, &(*check));
		if (*check == 1)
			return ;
		grid[1][pos] += 1;
	}
	grid[1][pos] = '1';
}

char	**ft_rush01(char **grid, int n)
{
	int	check;

	grid[1] = NULL;
	grid[1] = (char *) malloc(sizeof(char) * (n * n + 1));
	if (grid[1] == NULL)
		return (NULL);
	check = 0;
	grid[1][n * n] = 0;
	ft_backtrack(grid, 0, n, &check);
	if (check == 0)
		ft_putstr("Error\n");
	return (grid);
}

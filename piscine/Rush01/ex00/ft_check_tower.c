/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:47:04 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/21 14:51:51 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"
#include <stdlib.h>

int	ft_check_tower(char **grid, int pos, int n)
{
	if (ft_check_const(grid, pos, n))
		return (0);
	if (ft_check_doubles(grid, pos, n))
		return (0);
	if (ft_check_counts(grid, pos, n))
		return (0);
	return (1);
}

int	ft_check_const(char **grid, int pos, int n)
{
	int		col;
	int		row;
	char	max;

	col = pos % n;
	row = pos / n;
	max = n + 48;
	if ((grid[0][col] == max && row == 0 && grid[1][pos] != '1'))
		return (1);
	else if ((grid[0][col] == '1' && row == 0 && grid[1][pos] != max))
		return (1);
	else if ((grid[0][n + col] == max && row == n - 1 && grid[1][pos] != '1'))
		return (1);
	else if ((grid[0][n + col] == '1' && row == n - 1 && grid[1][pos] != max))
		return (1);
	else if ((grid[0][n * 2 + row] == max && col == 0 && grid[1][pos] != '1'))
		return (1);
	else if ((grid[0][n * 2 + row] == '1' && col == 0 && grid[1][pos] != max))
		return (1);
	return (0);
}

int	ft_check_counts(char **grid, int pos, int n)
{
	char	count[4];
	int		col;
	int		row;
	int		i;

	i = 0;
	while (i < 4)
		count[i++] = '1';
	ft_count_row_up(grid, pos, n, count);
	ft_count_row_down(grid, pos, n, count);
	ft_count_col_up(grid, pos, n, count);
	ft_count_col_down(grid, pos, n, count);
	col = pos % n;
	row = pos / n;
	if ((grid[0][col] != count[2] || grid[0][n + col] != count[3])
			&& row == n - 1)
		return (1);
	if ((grid[0][n * 2 + row] != count[0] || grid[0][n * 3 + row] != count[1])
			&& col == n - 1)
		return (1);
	return (0);
}

int	ft_check_doubles(char **grid, int pos, int n)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (grid[1][i] == grid[1][pos] && i % n == pos % n)
			return (1);
		if (grid[1][i] == grid[1][pos] && i / n == pos / n)
			return (1);
		i++;
	}
	return (0);
}

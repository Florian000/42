/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:39:09 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/21 14:55:04 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_count_row_up(char **grid, int pos, int n, char *count)
{
	int		i;
	char	max;

	i = 0;
	while (i <= pos)
	{
		max = grid[1][i];
		while (i / n == pos / n && i <= pos)
		{
			if (grid[1][i] > max)
			{
				max = grid[1][i];
				count[0]++;
			}
			i++;
		}
		i++;
	}
}

void	ft_count_row_down(char **grid, int pos, int n, char *count)
{
	int		i;
	char	max;

	i = pos;
	while (i >= 0)
	{
		max = grid[1][i];
		while (i / n == pos / n && i >= 0)
		{
			if (grid[1][i] > max)
			{
				max = grid[1][i];
					count[1]++;
			}
			i--;
		}
		i--;
	}
}

void	ft_count_col_up(char **grid, int pos, int n, char *count)
{
	int		i;
	char	max;

	i = 0;
	while (i <= pos)
	{
		max = grid[1][i];
		while (i % n == pos % n && i <= pos)
		{
			if (grid[1][i] > max)
			{
				max = grid[1][i];
				count[2]++;
			}
			i += n;
		}
		i++;
	}
}

void	ft_count_col_down(char **grid, int pos, int n, char *count)
{
	int		i;
	char	max;

	i = pos;
	while (i >= 0)
	{
		max = grid[1][i];
		while (i % n == pos % n && i >= 0)
		{
			if (grid[1][i] > max)
			{
				max = grid[1][i];
				count[3]++;
			}
			i -= n;
		}
		i--;
	}
}

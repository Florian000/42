/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:53:09 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/17 12:53:16 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printlines(char *board, int *nb)
{
	int	i;

	i = 0;
	while (i < 10)
		write(1, &board[i++], 1);
	write(1, "\n", 1);
	*nb = *nb + 1;
}

int	ft_check_position(char *board, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		if (board[i] == board[c])
			return (0);
		if (board[i] - i == board[c] - c || board[i] + i == board[c] + c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_backtrack(char *board, int col, int *nb)
{
	if (col == 10)
	{
		ft_printlines(board, &(*nb));
		return ;
	}
	board[col] = '0';
	while (board[col] <= '9' )
	{
		if (ft_check_position(board, col))
			ft_backtrack(board, col + 1, &(*nb));
		board[col]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		nb;

	nb = 0;
	ft_backtrack(board, 0, &nb);
	return (nb);
}

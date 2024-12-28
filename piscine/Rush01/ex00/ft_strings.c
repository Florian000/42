/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:19:10 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/21 14:19:19 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_free(char **grid)
{
	free(grid[0]);
	grid[0] = NULL;
	free(grid[1]);
	grid[1] = NULL;
}

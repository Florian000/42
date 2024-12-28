/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:23:54 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/21 14:37:36 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"
#include <stdlib.h>

int	ft_size(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i <= ft_strlen(input))
	{
		if (input[i] != ' ' && input[i])
			count++;
		i += 2;
	}
	if (count % 4 == 0)
		return (count / 4);
	return (0);
}

int	ft_check_input(char *input)
{
	int	size;
	int	i;

	size = ft_size(input);
	i = 0;
	if (input[0] == ' ' || input[ft_strlen(input)- 1] == ' ')
		return (0);
	if (size >= 3 && size <= 9)
	{
		while ((input[i] >= '1' && input[i] <= (size + 48)) || input[i] == ' ')
			i++;
		if (!input[i])
			return (size);
	}
	return (0);
}

char	*ft_clean_input(char *input, int n, char **grid)
{
	int	i;
	int	j;

	grid[0] = NULL;
	grid[0] = (char *) malloc(sizeof(char) * (n * n) + 1);
	if (grid[0] == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] != ' ')
		{
			grid[0][j] = input[i];
			j++;
		}
		i++;
	}
	grid[0][j] = 0;
	return (grid[0]);
}

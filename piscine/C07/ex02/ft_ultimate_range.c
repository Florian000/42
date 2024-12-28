/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:05:50 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/19 12:05:17 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min < max)
		size = max - min;
	else
		return (0);
	*range = NULL;
	*range = (int *) malloc(sizeof(int) * size);
	if (*range == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (size);
}

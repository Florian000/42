/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:05:28 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/16 12:21:58 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	size;
	int	i;

	if (min < max)
		size = max - min;
	else
		return (NULL);
	tab = NULL;
	tab = (int *) malloc(sizeof(int) * size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}

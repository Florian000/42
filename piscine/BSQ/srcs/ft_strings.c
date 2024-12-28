/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:27:21 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/31 00:32:20 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_bsq.h"

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
	write(1, "\n", 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = 0;
	return (dest);
}

int	*ft_strdup(char *src, int size, t_map *params)
{
	int	*tab;
	int	i;
	int	count;
	int	j;

	j = 0;
	i = 0;
	count = 0;
	tab = (int *) malloc(sizeof(int) * size - 1);
	if (tab == 0)
		return (0);
	while (src[i])
	{
		if (src[i] == '\n')
			count = 1;
		if (src[i] != '\n' && count == 1)
		{	
			if (src[i] == params->obs)
				tab[j++] = 0;
			else
				tab[j++] = 1;
		}
		i++;
	}
	return (tab);
}

int	*ft_clean(char *str, t_map *params)
{
	int	i;
	int	count;
	int	*map;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n' && count == 0)
			count = 1;
		if (str[i] != '\n' && count > 0)
			count++;
		i++;
	}
	map = ft_strdup(str, count, params);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 00:23:37 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/31 00:27:49 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bsq.h"

char	*ft_fill_square(t_map *params, int max, char *map)
{
	int	size;
	int	j;
	int	i;

	size = params->map[max];
	j = 0;
	while (j < size * params->len)
	{
		i = max + j;
		while (i < max + size + j)
		{
			map[i] = params->full;
			i++;
		}
		j += params->len;
	}
	return (map);
}

char	*ft_lines(t_map *params, char *map)
{
	int		i;
	int		j;
	char	*str;
	int		size;

	size = (params->len * params->lines + params->lines);
	str = NULL;
	str = (char *) malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (map[i])
	{
		if (i % params->len == 0 && i > 0)
			str[j++] = '\n';
		str[j++] = map[i++];
	}
	str[j] = 0;
	ft_free_str(map);
	return (str);
}

void	ft_print_map(t_map *params, int max)
{
	char	*map;

	map = ft_convert_map(params);
	if (!map)
		return ;
	map = ft_fill_square(params, max, map);
	map = ft_lines(params, map);
	ft_putstr(map);
	ft_free_str(map);
}

char	*ft_convert_map(t_map *params)
{
	int		size;
	char	*str;
	int		i;
	int		j;

	size = (params->len * params->lines);
	str = NULL;
	str = (char *) malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (params->map[j] > 0)
			str[i++] = params->empty;
		else
			str[i++] = params->obs;
		j++;
	}
	str[i] = 0;
	return (str);
}

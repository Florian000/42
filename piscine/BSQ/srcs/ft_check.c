/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:38:38 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/31 00:19:16 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_check_map(char *map, t_map *params)
{
	int	i;
	int	lines;

	lines = 0;
	i = ft_get_params(map, params);
	if (i == 0)
		return (0);
	params->len = ft_check_lines(map, i, params);
	while (map[i] && params->len > -1)
	{
		if (params->len != ft_check_lines(map, i, params))
			return (0);
		i += params->len +1;
		lines++;
	}
	if (lines != params->lines)
		return (0);
	return (1);
}

int	ft_get_params(char *map, t_map *params)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != '\n')
		i++;
	if (i < 4)
		return (0);
	j = 1 + i--;
	params->full = ft_is_printable(map[i--]);
	params->obs = ft_is_printable(map[i--]);
	params->empty = ft_is_printable(map[i--]);
	params->lines = ft_atoi(map, i);
	if (!ft_check_char(params))
		return (0);
	if (params->lines == 0)
		return (0);
	return (j);
}

int	ft_check_lines(char *map, int i, t_map *params)
{
	int	len;

	len = 0;
	while (map[i + len] != '\n')
	{
		if (map[i + len] != params->obs && map[i + len] != params->empty)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_check_char(t_map *params)
{
	if (!params->full || !params->obs || !params->empty)
		return (0);
	if (params->full == params->obs)
		return (0);
	if (params->obs == params->empty)
		return (0);
	if (params->full == params->empty)
		return (0);
	return (1);
}

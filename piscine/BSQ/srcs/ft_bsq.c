/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:10:43 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/31 00:36:25 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#include <stdlib.h>

int	ft_col(t_map *p, int i)
{
	int	size;

	size = p->map[i];
	i += size;
	size += i / p->len;
	while (p->map[i] != 0 && i / p->len <= size && i / p->len < p->lines)
	{
		i += p->len;
		if (i >= p->len * p->lines || p->map[i] == 0 || i / p->len >= p->lines)
		{
			i -= p->len;
			break ;
		}
	}
	if (i / p->len >= size && p->map[i] != 0)
		return (1);
	return (0);
}

int	ft_line(t_map *p, int i)
{
	int	size;
	int	j;

	size = p->map[i];
	j = i + p->len * size;
	i += p->len * size;
	size += i % (p->len);
	if (i >= p->len * p->lines)
		return (0);
	while (p->map[i] != 0 && i % p->len < size && i / p->len == j / p->len)
	{
		i++;
		if (i >= p->len * p->lines || p->map[i] == 0)
		{
			i--;
			break ;
		}
	}
	if (i % p->len >= size && p->map[i] != 0 && i / p->len == j / p->len)
		return (1);
	return (0);
}

int	ft_count(t_map *params, int i)
{
	if (i % params->len != 0 && params->map[i - 1] > 1)
		params->map[i] = params->map[i - 1] - 1;
	else if (i > params->len + 1 && params->map[i - params->len] > 1)
		params->map[i] = params->map[i - params->len] - 1;
	while (ft_line(params, i) && ft_col(params, i))
		params->map[i] += 1;
	return (params->map[i]);
}

void	ft_solve(t_map *params, int *max, int i)
{
	while (i < params->len * (params->lines - 1))
	{
		if (params->map[*max] >= params->len - i % params->len)
			i += params->len - i % params->len;
		new_max(ft_count(params, i), max, i, params->map[*max]);
		i++;
	}
}

int	ft_bsq(t_map *params)
{
	int	max;

	max = 0;
	ft_solve(params, &max, 0);
	return (max);
}

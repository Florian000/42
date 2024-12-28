/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 00:19:34 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/31 00:20:42 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bsq.h"

void	ft_free_str(char *str)
{
	free(str);
	str = NULL;
}

void	ft_free_params(t_map *params)
{
	params->lines = 0;
	params->len = 0;
	params->empty = 0;
	params->obs = 0;
	params->full = 0;
	free(params->map);
	params->map = NULL;
	free(params);
	params = NULL;
}

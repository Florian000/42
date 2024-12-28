/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:42:39 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/11 13:00:09 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	is_num;
	int	i;

	is_num = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			is_num = 0;
		i++;
	}
	return (is_num);
}

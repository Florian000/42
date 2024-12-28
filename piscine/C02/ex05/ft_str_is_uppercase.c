/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:45:12 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/11 13:01:52 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	is_upper;
	int	i;

	is_upper = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] < 65 || str[i] > 90)
			is_upper = 0;
		i++;
	}
	return (is_upper);
}

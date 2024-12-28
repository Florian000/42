/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:44:05 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/11 13:01:04 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	is_lower;
	int	i;

	is_lower = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] < 97 || str[i] > 122)
			is_lower = 0;
		i++;
	}
	return (is_lower);
}

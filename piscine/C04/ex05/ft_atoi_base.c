/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:22:24 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/15 01:00:26 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> 

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i;
		while (str[j])
		{
			if (str[i] == str[j + 1] || str[j] == '+' || str[j] == '-')
				return (0);
			else if (is_space(str[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	index_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	sign;
	int	i_base;

	i = 0;
	result = 0;
	sign = 1;
	if (ft_check_base(base))
	{
		while (is_space(str[i]))
			i++;
		while (str[i] == '+' || str[i] == '-')
			if (str[i++] == '-')
				sign *= -1;
		i_base = index_base(str[i], base);
		while (i_base != -1)
		{
			result = result * ft_check_base(base) + i_base;
			i_base = index_base(str[++i], base);
		}
		return (result * sign);
	}
	return (0);
}

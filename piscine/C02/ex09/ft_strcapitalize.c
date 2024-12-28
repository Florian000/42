/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:49:53 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/11 13:06:59 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	islow(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	isup(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (str[i])
	{
		if (isup(str[i]))
			str[i] += 32;
		if (i > 0)
		{
			if (!(isnum(str[i - 1]) || islow(str[i - 1]) || isup(str[i - 1])))
				b = 0;
			else
				b = 1;
		}
		if (b == 0 && islow(str[i]))
			str[i] -= 32;
		i++;
	}
	return (str);
}

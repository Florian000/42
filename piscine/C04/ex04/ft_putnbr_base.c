/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:21:46 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/15 00:59:00 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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
			else if (is_space(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				len;
	long long int	nb;

	nb = nbr;
	len = ft_check_base(base);
	if (len > 1)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb >= len)
		{
			ft_putnbr_base(nb / len, base);
		}
		write(1, &base[nb % len], 1);
	}
}

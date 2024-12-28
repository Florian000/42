/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:27:56 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/30 13:19:34 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long int nb)
{
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

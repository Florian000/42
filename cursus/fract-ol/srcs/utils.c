/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:00:12 by fgranger          #+#    #+#             */
/*   Updated: 2024/01/01 14:51:28 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	malloc_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

double	f_abs(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

double	atodbl(char *s)
{
	long	nb;
	double	dec;
	double	pow;
	int		sign;

	nb = 0;
	dec = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		nb = (nb * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		dec = dec + (*s++ - 48) * pow;
	}
	return ((nb + dec) * sign);
}

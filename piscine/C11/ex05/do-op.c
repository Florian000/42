/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:53:16 by fgranger          #+#    #+#             */
/*   Updated: 2022/09/01 04:23:30 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"
#include <unistd.h>

int	ft_err(long int a, long int b)
{
	(void)a;
	(void)b;
	return (0);
}

int	select_ft(char *str)
{
	char	*ops;
	int		i;

	i = 0;
	ops = "+-/*%";
	while (ops[i] && !str[1])
	{
		if (str[0] == ops[i])
			return (i);
		i++;
	}
	return (5);
}

int	(*functions(char *ops)) (long int a, long int b)
{
	int	(*f[6])(long int, long int);

	f[0] = &ft_add;
	f[1] = &ft_sub;
	f[2] = &ft_div;
	f[3] = &ft_mul;
	f[4] = &ft_mod;
	f[5] = &ft_err;
	return (f[select_ft(ops)]);
}

void	ft_doop(long int a, char *ops, long int b)
{
	int	(*f)(long int, long int);

	if (ops[0] == '/' && b == 0)
		ft_putstr("Stop : division by zero\n");
	else if (ops[0] == '%' && b == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
	{
		f = functions(ops);
		ft_putnbr(f(a, b));
		write(1, "\n", 1);
	}
}

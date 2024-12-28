/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:08:52 by fgranger          #+#    #+#             */
/*   Updated: 2024/03/02 14:39:41 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (len);
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(const char *str, int fd)
{
	if (str == NULL)
		return ;
	write(fd, str, ft_strlen(str));
}

static int	ft_num_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	return (len);
}

long	ft_atol(char *str)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (-1);
	if (ft_num_len(str + i) > 10)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	if (num > INT_MAX)
		return (-1);
	return (num);
}

void	error_handler(const char *error)
{
	ft_putstr_fd(error, 2);
}

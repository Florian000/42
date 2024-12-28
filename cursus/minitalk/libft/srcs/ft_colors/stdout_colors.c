/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <florian.granger@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:02:39 by fgranger          #+#    #+#             */
/*   Updated: 2023/02/05 15:34:12 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	stdout_red(void)
{
	ft_printf("\033[0;31m");
}

void	stdout_yellow(void)
{
	ft_printf("\033[0;33m");
}

void	stdout_green(void)
{
	ft_printf("\033[0;32m");
}

void	stdout_blue(void)
{
	ft_printf("\033[0;34m");
}

void	stdout_reset(void)
{
	ft_printf("\033[0m");
}

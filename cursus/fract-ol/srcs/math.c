/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:00:00 by fgranger          #+#    #+#             */
/*   Updated: 2024/01/01 20:18:03 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	map(double n, double min, double max)
{
	return ((max - min) * (n - 0) / (WIDTH - 0) + min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

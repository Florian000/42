/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:01:11 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/31 22:10:38 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_pixel_put(int x, int y, t_fractol *f, int color)
{
	char	*dst;

	dst = f->pix_ptr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_fractol(t_fractol *f, void (*fractal)(t_fractol*, int, int))
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIDTH)
	{
		x = -1;
		while (++x < HEIGHT)
			fractal(f, x, y);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->ptr, 0, 0);
}

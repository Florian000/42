/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:39:44 by fgranger          #+#    #+#             */
/*   Updated: 2024/01/01 20:34:17 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_fractol *f, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.x = map(x, f->min.x, f->max.x);
	z.y = map(y, f->min.y, f->max.y);
	c.x = z.x;
	c.y = z.y;
	while (++i < f->iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->esc)
			return (my_pixel_put(x, y, f, f->color.div * i));
	}
	my_pixel_put(x, y, f, f->color.conv);
}

void	julia(t_fractol *f, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.x = map(x, f->min.x, f->max.x);
	z.y = map(y, f->min.y, f->max.y);
	c.x = f->julia.x;
	c.y = f->julia.y;
	while (++i < f->iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->esc)
			return (my_pixel_put(x, y, f, f->color.div * i));
	}
	my_pixel_put(x, y, f, f->color.conv);
}

void	burningship(t_fractol *f, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	t_complex	tmp;

	i = 0;
	z.x = map(x, f->min.x, f->max.x);
	z.y = map(y, f->min.y, f->max.y);
	c.x = z.x;
	c.y = z.y;
	while (++i < f->iter)
	{
		tmp = sum_complex(square_complex(z), c);
		z.y = f_abs(2.0 * z.x * z.y) + c.y;
		z.x = f_abs(tmp.x);
		if ((z.x * z.x) + (z.y * z.y) > f->esc)
			return (my_pixel_put(x, y, f, f->color.div * i));
	}
	my_pixel_put(x, y, f, f->color.conv);
}

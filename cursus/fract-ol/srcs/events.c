/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 22:04:39 by fgranger          #+#    #+#             */
/*   Updated: 2024/01/01 20:34:51 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	shift_fractal(t_fractol *f, int sign, int plan)
{
	double	shift;

	shift = 0.1 * sign;
	if (plan == 1)
	{
		f->min.x += shift;
		f->max.x += shift;
	}
	else if (plan == 0)
	{
		f->min.y += shift;
		f->max.y += shift;
	}
}

int	handle_exit(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->ptr);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(EXIT_SUCCESS);
}

int	handle_key(int key, t_fractol *f)
{
	if (key == XK_Escape)
		handle_exit(f);
	else if (key == XK_Left)
		shift_fractal(f, 1, 1);
	else if (key == XK_Right)
		shift_fractal(f, -1, 1);
	else if (key == XK_Up)
		shift_fractal(f, 1, 0);
	else if (key == XK_Down)
		shift_fractal(f, -1, 0);
	else if (key == 100)
		f->dynamic_julia *= -1;
	else if (key == 106)
		init_julia(f, NULL, 0);
	else if (key == 99)
		f->color.div += (255 * 255 * 255) / 100;
	else if (key == 98)
		init_burningship(f, 0);
	else if (key == 109)
		init_mandelbrot(f, 0);
	print_fractol(f, f->fractal);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	t_complex	mouse_pos;
	t_complex	size;

	mouse_pos.x = map(x, f->min.x, f->max.x);
	mouse_pos.y = map(y, f->min.y, f->max.y);
	size.x = (f->max.x - f->min.x);
	size.y = (f->max.y - f->min.y);
	if (button == Button5)
	{
		f->min.x = mouse_pos.x - (size.x * 1.5 / 2);
		f->max.x = mouse_pos.x + (size.x * 1.5 / 2);
		f->min.y = mouse_pos.y - (size.y * 1.5 / 2);
		f->max.y = mouse_pos.y + (size.y * 1.5 / 2);
	}
	else if (button == Button4)
	{
		f->min.x = mouse_pos.x - (size.x / 1.5 / 2);
		f->max.x = mouse_pos.x + (size.x / 1.5 / 2);
		f->min.y = mouse_pos.y - (size.y / 1.5 / 2);
		f->max.y = mouse_pos.y + (size.y / 1.5 / 2);
	}
	else if (button == Button1 && f->dynamic_julia == 1)
		julia_track(x, y, f);
	print_fractol(f, f->fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractol *f)
{
	if (!ft_strncmp(f->name, "julia", 5))
	{
		f->julia.x = map(x, f->min.x, f->max.x);
		f->julia.y = map(y, f->min.y, f->max.y);
		print_fractol(f, f->fractal);
	}
	return (0);
}

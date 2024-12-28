/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:59:54 by fgranger          #+#    #+#             */
/*   Updated: 2024/01/01 21:18:54 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_events(t_fractol *f)
{
	mlx_hook(f->win, KeyPress, KeyPressMask, handle_key, f);
	mlx_hook(f->win, ButtonPress, ButtonPressMask, handle_mouse, f);
	mlx_hook(f->win, DestroyNotify, StructureNotifyMask, handle_exit, f);
}

void	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		malloc_error();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
		malloc_error();
	}
	f->ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->ptr)
	{
		mlx_destroy_window(f->mlx, f->win);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
		malloc_error();
	}
	f->pix_ptr = mlx_get_data_addr(f->ptr, &f->bpp, &f->line_len, &f->endian);
	init_events(f);
}

int	init_mandelbrot(t_fractol *f, int first)
{
	f->name = "mandelbrot";
	f->esc = 4.0;
	f->min.x = -2.2;
	f->max.x = 1.3;
	f->min.y = -1.55;
	f->max.y = 1.45;
	f->dynamic_julia = -1;
	f->fractal = mandelbrot;
	f->color.div = PSYCHEDELIC_PURPLE;
	f->color.conv = WHITE;
	if (first == 1)
		init_fractol(f);
	return (0);
}

int	init_julia(t_fractol *f, char **av, int first)
{
	f->name = "julia";
	f->esc = 4;
	f->min.x = -1.8;
	f->max.x = 1.7;
	f->min.y = -1.55;
	f->max.y = 1.45;
	f->color.div = ELECTRIC_BLUE;
	f->color.conv = BLACK;
	f->dynamic_julia = -1;
	f->fractal = julia;
	f->julia.x = -0.745429;
	f->julia.y = 0.05;
	if (first == 1)
	{
		f->julia.x = atodbl(av[2]);
		f->julia.y = atodbl(av[3]);
		if (f->julia.x > 2 || f->julia.x < -2 || f->julia.y > 2
			|| f->julia.y < -2)
			return (1);
		init_fractol(f);
	}
	return (0);
}

int	init_burningship(t_fractol *f, int first)
{
	f->name = "burningship";
	f->esc = 4;
	f->min.x = -2.2;
	f->max.x = 1.3;
	f->min.y = -1.85;
	f->max.y = 1.15;
	f->dynamic_julia = -1;
	f->color.div = LAVA_RED;
	f->color.conv = BLACK;
	f->fractal = burningship;
	if (first == 1)
		init_fractol(f);
	return (0);
}

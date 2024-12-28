/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:44:24 by fgranger          #+#    #+#             */
/*   Updated: 2024/01/05 21:01:54 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	parser(int ac, char **av, t_fractol *f)
{
	if (ac == 3 && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		if (ft_atoi(av[2]) < 10 || ft_atoi(av[2]) > 1000)
			return (1);
		f->iter = ft_atoi(av[2]);
		return (init_mandelbrot(f, 1));
	}
	else if (ac == 5 && !ft_strncmp(av[1], "julia", 5))
	{
		if (ft_atoi(av[4]) < 10 || ft_atoi(av[4]) > 1000)
			return (1);
		f->iter = ft_atoi(av[4]);
		return (init_julia(f, av, 1));
	}
	else if (ac == 3 && !ft_strncmp(av[1], "burningship", 11))
	{
		if (ft_atoi(av[2]) < 10 || ft_atoi(av[2]) > 1000)
			return (1);
		f->iter = ft_atoi(av[2]);
		return (init_burningship(f, 1));
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (parser(ac, av, &f))
		return (ft_putstr_fd(ERROR_MSG, STDERR_FILENO), EXIT_FAILURE);
	ft_putstr_fd(CMD_DISPLAY, 1);
	print_fractol(&f, f.fractal);
	mlx_loop(f.mlx);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:31:19 by fgranger          #+#    #+#             */
/*   Updated: 2024/01/01 20:33:38 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800
# define ERROR_MSG "Wrong arguments passed !\n\
Usage :\n\
./fractol mandelbrot <nb_iter>\n\
./fractol julia <x> <y> <nb_iter> (x and y must be\
between -2 and 2)\n\
./fractol burningship <nb_iter>\n\
nb_iter must be between 10 and 1000\n"
# define CMD_DISPLAY "Available commandes : \n\
Arrowkey up = move the fractal up \n\
Arrowkey down = move the fractal down \n\
Arrowkey left = move the fractal to the left \n\
Arrowkey right = move the fractal to the right\n\
Scroll up = zoom in\n\
Scroll out = zoom out\n\
C = change color\n\
J = Julia set\n\
D = Activate/Unactivate Dynamic Julia set\n\
left click (only with dynamic julia activated) = \
change julia set based on mouse position\n\
M = Mandelbrot\n\
B = Burningship\n"

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define PSYCHEDELIC_PURPLE 0x660066
# define ELECTRIC_BLUE   0x0066FF
# define LAVA_RED        0xFF3300

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_color
{
	int	div;
	int	conv;
}				t_color;

typedef struct s_fractol
{
	char		*name;
	void		*mlx;
	void		*win;
	void		*ptr;
	char		*pix_ptr;
	int			bpp;
	int			endian;
	int			line_len;

	t_complex	min;
	t_complex	max;
	t_complex	julia;

	double		esc;
	int			iter;
	int			dynamic_julia;
	void		(*fractal)(struct s_fractol*, int, int);

	t_color		color;
}		t_fractol;

void		init_fractol(t_fractol *f);

int			handle_key(int key, t_fractol *f);
int			handle_exit(t_fractol *f);
int			handle_mouse(int button, int x, int y, t_fractol *f);

void		print_fractol(t_fractol *f, void (*fractal)(t_fractol*, int, int));
double		map(double n, double min, double max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

void		malloc_error(void);
double		atodbl(char *s);
double		f_abs(double nb);

void		my_pixel_put(int x, int y, t_fractol *f, int color);
void		init_events(t_fractol *f);
int			init_mandelbrot(t_fractol *f, int first);

void		mandelbrot(t_fractol *f, int x, int y);
void		julia(t_fractol *f, int x, int y);
int			init_julia(t_fractol *f, char **av, int first);

int			init_burningship(t_fractol *f, int first);
void		burningship(t_fractol *f, int x, int y);

int			julia_track(int x, int y, t_fractol *f);
#endif

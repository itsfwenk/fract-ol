/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:17:47 by fli               #+#    #+#             */
/*   Updated: 2024/07/18 19:00:01 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <mlx.h>
# include "libft.h"

# ifndef TRUE
#  define TRUE 1

# endif

# ifndef FALSE
#  define FALSE 0

# endif

# ifndef WIDTH
#  define WIDTH 1200

# endif

# ifndef HEIGHT
#  define HEIGHT 900

# endif

# ifndef ITER_MAX
#  define ITER_MAX 150

# endif

# ifndef BITS_PER_PX
#  define BITS_PER_PX 32

# endif

# ifndef BYTES_PER_PX
#  define BYTES_PER_PX 4

# endif

# ifndef UP
#  define UP 65362

# endif

# ifndef DOWN
#  define DOWN 65364

# endif

# ifndef LEFT
#  define LEFT 65361

# endif

# ifndef RIGHT
#  define RIGHT 65363

# endif

typedef struct	s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	char	set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	cr;
	double	ci;
	int		*palette;
	int		color1;
	int		color2;
	int		color3;
	int		color_num;
}	t_fractal;

/******************* FRACTOL *******************/

// void	parsing_fractol(t_fractal *f, int ac, char **av);

// int		main(int argc, char **argv);

/******************* INIT_FRACTOL *******************/

void	f_init(t_fractal *f);

void	def_cplane(t_fractal *f);

void	create_img(t_fractal *f);

void	init_img(t_fractal *f);

/******************* FRACTOL_UTILS *******************/

int		clean_exit(t_fractal *f);

/******************* ATOD *******************/

double	ft_atod(const char *nptr);

/******************* COLOR_FRACTOL *******************/

void	def_color(t_fractal *f, int color);

/******************* DRAW_FRACTOL *******************/

void	draw_fract(t_fractal *f);

/******************* PXTOD *******************/

double	pxtod_x(t_fractal *f, int x);

double	pxtod_y(t_fractal *f, int y);

/******************* CALC_FRACT *******************/

int		calc_fract(t_fractal *f, int cx, int cy);

/******************* MANDEL_CALC *******************/

int		mandel_calc(double cx, double cy);

/******************* JULIA_CALC *******************/

int		julia_calc(double zx, double zy, t_fractal *f);

/******************* BURNSHIP_CALC *******************/

int		burnship_calc(double cx, double cy);

/******************* ZOOM *******************/

int		mouse_event(int keycode, int x, int y, t_fractal *mlx);

void	move(t_fractal *f, double distance, char direction);


/******************* KEY_EVENT *******************/

int		key_event(int keycode, void *param);

/******************* PRINT_GUIDE *******************/

void	print_guide(t_fractal *f);

#endif

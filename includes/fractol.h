/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:17:47 by fli               #+#    #+#             */
/*   Updated: 2024/07/16 21:03:25 by fli              ###   ########.fr       */
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
	double	kr;
	double	ki;
	double	zoom;
	int		*palette;
	int		color;
}	t_fractal;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/******************* FRACTOL *******************/

// void	parsing_fractol(t_fractal *f, int ac, char **av);

int	main(int argc, char **argv);

/******************* INIT_FRACTOL *******************/

void	def_cplane(t_fractal *f);

void	create_img(t_fractal *f);

void	init_img(t_fractal *f);

/******************* FRACTOL_UTILS *******************/

int	clean_exit(t_fractal *f);

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

int		mandel_calc(double	cx, double cy);

/******************* ZOOM *******************/

int		zoom_dezoom(int mcode, t_fractal *f);

#endif

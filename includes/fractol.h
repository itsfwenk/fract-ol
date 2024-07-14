/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:17:47 by fli               #+#    #+#             */
/*   Updated: 2024/07/14 13:44:33 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <mlx.h>
# include "libft.h"

# ifndef TRUE
#  define TRUE 1

# endif

# ifndef FALSE
#  define FALSE 0

# endif

# ifndef LENGTH
#  define LENGTH 1200

# endif

# ifndef WIDTH
#  define WIDTH 900

# endif

# ifndef ITER_MAX
#  define ITER_MAX 150

# endif

typedef struct	s_fractal
{
	char	name[20];
	double	cx;
	double	cy;
	int	px;
	int	py;
	double	x;
	double	y;
	int color;
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/******************* PXTOD *******************/

double	pxtod_x(int x);

double	pxtod_y(int y);

/******************* MANDEL_CALC *******************/

void	mandel_calc(t_fractal *z, t_data img);

#endif

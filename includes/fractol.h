/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:17:47 by fli               #+#    #+#             */
/*   Updated: 2024/07/12 19:22:31 by fli              ###   ########.fr       */
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

# ifndef ITER_MAX
#  define ITER_MAX 150

# endif

typedef struct	s_fractal
{
	char	name[20];
	double	cx;
	double	cy;
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

/******************* PUSH_SWAP *******************/

void	*mlx_init();

#endif

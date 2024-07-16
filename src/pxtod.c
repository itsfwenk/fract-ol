/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxtod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:27:55 by fli               #+#    #+#             */
/*   Updated: 2024/07/16 13:15:11 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pxtod_x(t_fractal *f, int x)
{
	double	zx;

	zx = f->min_r + ((double)x * (f->max_r - f->min_r) / WIDTH);
	// dprintf(2, "set : %c, px : %d, zx : %f\n", (*f).set, x, zx);
	return (zx);
}

double	pxtod_y(t_fractal *f, int y)
{
	double	zy;
	zy = f->max_i + ((double)y * (f->min_i - f->max_i) / HEIGHT);

	// dprintf(2, "set : %c, py : %d, zy : %f\n", (*f).set, y,zy);
	return (zy);
}

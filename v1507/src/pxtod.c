/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxtod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:27:55 by fli               #+#    #+#             */
/*   Updated: 2024/07/15 11:26:06 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pxtod_x(t_fractal *f, int x)
{
	double	zx;

	zx = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	return (zx);
}

double	pxtod_y(t_fractal *f, int y)
{
	double	zy;

	zy = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
	return (zy);
}

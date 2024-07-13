/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxtod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:27:55 by fli               #+#    #+#             */
/*   Updated: 2024/07/13 18:10:09 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pxtod_x(int x)
{
	double	zx;

	zx = ((double)x - (WIDTH / 2)) / (WIDTH / 3) -0.5;
	return (zx);
}

double	pxtod_y(int y)
{
	double	zy;

	zy = ((double)y - (LENGTH / 2)) / (WIDTH / 3)-0.5;
	return (zy);
}

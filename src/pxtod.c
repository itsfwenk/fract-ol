/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxtod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:27:55 by fli               #+#    #+#             */
/*   Updated: 2024/07/14 13:55:42 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pxtod_x(int x)
{
	double	zx;

	zx = (-2) + ((double)x * (4) / LENGTH);
	return (zx);
}

double	pxtod_y(int y)
{
	double	zy;

	zy = (-3) + ((double)y * (4) / WIDTH);
	return (zy);
}

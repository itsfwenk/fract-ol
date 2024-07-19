/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:09:53 by fli               #+#    #+#             */
/*   Updated: 2024/07/19 14:10:27 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandel_calc(double cx, double cy)
{
	int		i;
	double	zx;
	double	zy;
	double	temp_zx;

	i = 0;
	zx = 0;
	zy = 0;
	while (i < ITER_MAX)
	{
		if ((zx) * (zx) + (zy) * (zy) > 4)
			break ;
		temp_zx = (zx) * (zx) - (zy) * (zy) + cx;
		zy = 2.0 * (zx) * (zy) + cy;
		zx = temp_zx;
		i++;
	}
	return (i);
}

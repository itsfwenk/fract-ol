/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:17:02 by fli               #+#    #+#             */
/*   Updated: 2024/07/18 17:52:51 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	v_abs(double value)
{
	if (value < 0)
		return (value * (double)-1.0);
	else
		return (value);
}

int	burnship_calc(double	cx, double cy)
{
	int	i;
	double	zx;
	double	zy;
	double	temp_zx;

	i = 0;
	zx = 0;
	zy = 0;
	while (i < ITER_MAX)
	{
		if ((zx)*(zx) + (zy)*(zy) > 4.0)
			break ;
		temp_zx = (zx) * (zx) - (zy) * (zy) + cx;
		zy = v_abs(2.0 * (zx) * (zy)) + cy;
		zx = temp_zx;
		i++;
	}
	return (i);
}

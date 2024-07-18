/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:26:37 by fli               #+#    #+#             */
/*   Updated: 2024/07/18 12:50:26 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_calc(double zx, double zy, t_fractal *f)
{
	int	i;
	double	temp_zx;

	i = 0;
	while (i < ITER_MAX)
	{
		if ((zx)*(zx) + (zy)*(zy) > 4)
			break ;
		temp_zx = (zx) * (zx) - (zy) * (zy) + f->cr;
		zy = 2.0 * (zx) * (zy) + f->ci;
		zx = temp_zx;
		i++;
	}
	return (i);
}

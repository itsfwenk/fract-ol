/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:09:53 by fli               #+#    #+#             */
/*   Updated: 2024/07/14 14:15:06 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_calc(t_fractal *z, t_data img)
{
	int	i;
	int	temp_x;

	z->cx = pxtod_x(z->px);
	z->cy = pxtod_y(z->py);
	dprintf(2, "cx = %f\n", z->cx );
	dprintf(2, "cy = %f\n", z->cy );
	i = 0;
	while (i < ITER_MAX)
	{
		temp_x = (z->x) * (z->x) - (z->y) * (z->y) + z->cx;
		z->y = 2.0 * (z->x) * (z->y) + z->cy;
		z->x = temp_x;
		i++;
		if ((z->x)*(z->x) + (z->y)*(z->y) + z->cx >= 4)
			break ;
	}
	if (i == ITER_MAX)
		my_mlx_pixel_put(&img, z->px, z->py, 0x00000000+i);
	else
	{
		// dprintf(2, "i = %d\n", i);
		my_mlx_pixel_put(&img, z->px, z->py, 0xFFFFFFFF);
	}
	// if (i == ITER_MAX)
	// 	put_color_to_pixel(z, z->x, z->y, 0x00000000);
	// else
	// 	put_color_to_pixel(z, z->x, z->y, (z->color * i));
}

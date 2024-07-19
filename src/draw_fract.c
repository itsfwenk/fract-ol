/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:41:52 by fli               #+#    #+#             */
/*   Updated: 2024/07/19 14:16:03 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_pixel_color(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = (f->buf) + (y * WIDTH * BYTES_PER_PX + x * (BITS_PER_PX / 8));
	*(unsigned int *)dst = color;
}

void	draw_fract(t_fractal *f)
{
	int	px;
	int	py;
	int	i;

	py = 0;
	while (py++ < HEIGHT)
	{
		px = 0;
		while (px++ < WIDTH)
		{
			if (f->set == 'm')
				i = mandel_calc(pxtod_x(f, px), pxtod_y(f, py));
			else if (f->set == 'j')
				i = julia_calc(pxtod_x(f, px), pxtod_y(f, py), f);
			else if (f->set == 'b')
				i = burnship_calc(pxtod_x(f, px), pxtod_y(f, py));
			if (i == ITER_MAX)
				set_pixel_color(f, px, py, 0x00000000);
			else
				set_pixel_color(f, px, py, f->palette[i]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:41:52 by fli               #+#    #+#             */
/*   Updated: 2024/07/16 13:29:42 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_pixel_color(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = (f->buf) + (y * WIDTH  * BYTES_PER_PX + x * (BITS_PER_PX / 8));
	*(unsigned int*)dst = color;
	// f->buf[x * 4 + y * WIDTH * 4] = color;
	// f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	// f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	// f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
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
			// else if (f->set == 'j')
			// 	i = julia_calc();
			// else if (f->set == 'b')
			// 	i = burn_calc();

			if (i == ITER_MAX)
				set_pixel_color(f, px, py, 0x00000000);
			else
				set_pixel_color(f, px, py, f->palette[i]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:55:03 by fli               #+#    #+#             */
/*   Updated: 2024/07/19 13:53:30 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_shift(t_fractal *f)
{
	if (f->color_num == 1)
	{
		f->color_num = 2;
		def_color(f, f->color2);
	}
	else if (f->color_num == 2)
	{
		f->color_num = 3;
		def_color(f, f->color3);
	}
	else if (f->color_num == 3)
	{
		f->color_num = 1;
		def_color(f, f->color1);
	}
}

int	key_event(int keycode, t_fractal *f)
{
	if (keycode == 65307)
		clean_exit(f);
	else if (keycode == 99)
		color_shift(f);
	else if (keycode == UP)
		move(f, 0.2, 'U');
	else if (keycode == DOWN)
		move(f, 0.2, 'D');
	else if (keycode == LEFT)
		move(f, 0.2, 'L');
	else if (keycode == RIGHT)
		move(f, 0.2, 'R');
	else if (keycode == 32)
	{
		printf("min r : %f\n", f->min_r);
		printf("max r : %f\n", f->max_r);
		printf("min i : %f\n", f->min_i);
		printf("max i : %f\n", f->max_i);
	}
	draw_fract(f);
	return (0);
}

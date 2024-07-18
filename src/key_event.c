/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:55:03 by fli               #+#    #+#             */
/*   Updated: 2024/07/18 19:05:01 by fli              ###   ########.fr       */
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

// static void	move_key(t_fractal *f, int direction)
// {
// 	double	center_r;
// 	double	center_i;

// 	center_r = f->max_r - f->min_r;
// 	center_i = f->max_i - f->min_i;
// 	if (direction == RIGHT)
// 	{
// 		f->min_r -= 0.25;
// 		f->max_r += 0.25;
// 	}
// 	else if (direction == LEFT)
// 	{
// 		f->min_r += 0.25;
// 		f->max_r -= 0.25;
// 	}
// 	else if (direction == DOWN)
// 	{
// 		f->min_i += 0.25;
// 		f->max_i -= 0.25;
// 	}
// 	else if (direction == UP)
// 	{
// 		f->min_i -= 0.25;
// 		f->max_i += 0.25;
// 	}
// }

int	key_event(int keycode, void *param)
{
	if (keycode == 65307)
		clean_exit(param);
	else if (keycode == 99)
		color_shift(param);
	else if (keycode == UP)
		move(param, 0.2, 'U');
	else if (keycode == DOWN)
		move(param, 0.2, 'D');
	else if (keycode == LEFT)
		move(param, 0.2, 'L');
	else if (keycode == RIGHT)
		move(param, 0.2, 'R');
	draw_fract(param);
	return (0);
}

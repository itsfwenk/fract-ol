/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:19:42 by fli               #+#    #+#             */
/*   Updated: 2024/07/17 13:17:45 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static void	zoom(t_fractal *f, double zoom)
// {
// 	double	center_r;
// 	double	center_i;

// 	center_r = f->min_r - f->max_r;
// 	center_i = f->min_i - f->max_i;
// 	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
// 	f->min_r = f->max_r + zoom * center_r;
// 	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
// 	f->max_i = f->min_i + zoom * center_i;
// }

// int	zoom_dezoom(t_fractal *f)
// {
// 	// if (keycode == 4)
// 	// 	zoom(f, 0.5);
// 	// if (keycode == 5)
// 		zoom(f, 2);
// 	draw_fract(f);
// 	return (0);
// }

static void	zoom(t_fractal *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

static void	move(t_fractal *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}

int	mouse_event(int keycode, int x, int y, t_fractal *mlx)
{
	if (keycode == 4)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == 5)
		zoom(mlx, 2);
	// else if (keycode == MOUSE_BTN)
	// {
	// 	if (mlx->set == JULIA)
	// 		julia_shift(x, y, mlx);
	// }
	else
		return (0);
	draw_fract(mlx);
	return (0);
}

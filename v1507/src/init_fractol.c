/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:32:04 by fli               #+#    #+#             */
/*   Updated: 2024/07/15 16:32:17 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	f_init(t_fractal *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->kr = 0;
	f->ki = 0;
	f->zoom = 1;
	f->palette = NULL;
	f->color = 0x0000FF00;
}

void	def_cplane(t_fractal *f)
{
	if (f->set == 'm')
	{
		f->min_r = -4;
		f->max_r = 4;
		f->min_i = f->min_r * HEIGHT / WIDTH;
		f->max_i = f->max_r * HEIGHT / WIDTH;
	}
}

void	create_img(t_fractal *f)
{
	int	bit_per_px;
	int	line_length;
	int	endian;

	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (f->img == NULL)
		clean_exit(f);
	f->buf = mlx_get_data_addr(f->img, &bit_per_px, &line_length, &endian);
}

void	init_img(t_fractal *f)
{
	f_init(f);
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		clean_exit(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (f->win == NULL)
		clean_exit(f);
	create_img(f);
	def_cplane(f);
	f->palette = malloc((ITER_MAX + 1) * sizeof(int));
	if (f->palette == NULL)
		clean_exit(f);
	def_color(f, f->color);
}

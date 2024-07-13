/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:37:32 by fli               #+#    #+#             */
/*   Updated: 2024/07/13 17:38:19 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, LENGTH, WIDTH, "Mandelbrot");
	img.img = mlx_new_image(mlx, LENGTH, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	t_fractal *mandel;
	mandel = malloc(sizeof(t_fractal));
	mandel->cx = 0;
	mandel->cy = 0;
	mandel->x = 0;
	mandel->y = 0;
	mandel->px = 0;
	mandel->py = 0;
	while (mandel->py <= WIDTH)
	{
		while (mandel->px <= LENGTH)
		{
			mandel_calc(mandel, img);
			(mandel->px)++;
			mandel->x = 0;
			mandel->y = 0;
		}
		(mandel->px) = 0;
		(mandel->py)++;
	}
	// while (i < 200)
	// 	my_mlx_pixel_put(&img, 5, i++, 0x00FF0000);
	//  i = 5;
	// while (i < 200)
	// 	my_mlx_pixel_put(&img, i++, 5, 0x00FF0000);
	// i = 5;
	// while (i < 200)
	// 	my_mlx_pixel_put(&img, 200, i++, 0x00FF0000);
	// i = 5;
	// while (i < 200)
	// 	my_mlx_pixel_put(&img, i++, 200, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

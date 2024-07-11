/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:37:32 by fli               #+#    #+#             */
/*   Updated: 2024/07/11 18:18:34 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

#include<stdio.h>
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 540, "Hello world!");
	img.img = mlx_new_image(mlx, 960, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
								printf("%d - %d\n", img.bits_per_pixel, img.line_length);
	int i = 5;
	while (i < 200)
		my_mlx_pixel_put(&img, 5, i++, 0x00FF0000);
	 i = 5;
	while (i < 200)
		my_mlx_pixel_put(&img, i++, 5, 0x00FF0000);
	i = 5;
	while (i < 200)
		my_mlx_pixel_put(&img, 200, i++, 0x00FF0000);
	i = 5;
	while (i < 200)
		my_mlx_pixel_put(&img, i++, 200, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

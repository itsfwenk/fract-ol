/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:37:32 by fli               #+#    #+#             */
/*   Updated: 2024/07/15 16:42:00 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;

// }

static void	parsing_fractol(t_fractal *f, int ac, char **av)
{
	(void)ac;
	if (ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot") + 1) == 0)
		f->set = 'm';
	if (ft_strncmp(av[1], "julia", ft_strlen("julia") + 1) == 0)
		f->set = 'j';
	if (ft_strncmp(av[1], "burningship", ft_strlen("burningship") + 1) == 0)
		f->set = 'b';
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc < 2)
		return (FALSE);
	parsing_fractol(&f, argc, argv);
	init_img(&f);
	draw_fract(&f);
	mlx_loop(f.mlx);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");
// 	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	t_fractal *mandel;
// 	mandel = malloc(sizeof(t_fractal));
// 	mandel->cx = 0;
// 	mandel->cy = 0;
// 	mandel->x = 0;
// 	mandel->y = 0;
// 	mandel->px = 0;
// 	mandel->py = 0;
// 	while (mandel->py <= WIDTH)
// 	{
// 		while (mandel->px <= LENGTH)
// 		{
// 			mandel_calc(mandel, img);
// 			(mandel->px)++;
// 			mandel->x = 0;
// 			mandel->y = 0;
// 		}
// 		(mandel->px) = 0;
// 		(mandel->py)++;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

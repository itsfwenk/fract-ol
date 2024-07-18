/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:37:32 by fli               #+#    #+#             */
/*   Updated: 2024/07/18 15:03:11 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;

// }

static void	check_julia(t_fractal *f, int ac, char **av)
{
	if (ac == 4)
	{
		if (!ft_strchr(av[2], '.') || !ft_strchr(av[3], '.'))
			print_guide(f);
		f->cr = ft_atod(av[2]);
		f->ci = ft_atod(av[3]);
	}
	else
	{
		if (!ft_strchr(av[2], '.'))
			print_guide(f);
		f->cr = ft_atod(av[2]);
		f->ci = 0;
	}
}

static void	parsing_fractol(t_fractal *f, int ac, char **av)
{
	(void)ac;
	if (ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot") + 1) == 0)
		f->set = 'm';
	if (ft_strncmp(av[1], "julia", ft_strlen("julia") + 1) == 0)
	{
		f->set = 'j';
		if (ac == 4 || ac == 3)
			check_julia(f, ac, av);
		else
			print_guide(f);
	}
	if (ft_strncmp(av[1], "burningship", ft_strlen("burningship") + 1) == 0)
		f->set = 'b';
}

int	main(int ac, char **av)
{
	t_fractal	f;

	f_init(&f);
	if (ac < 2)
		print_guide(&f);
	parsing_fractol(&f, ac, av);
	init_img(&f);
	draw_fract(&f);
	mlx_hook(f.win, 17, 0, clean_exit, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}

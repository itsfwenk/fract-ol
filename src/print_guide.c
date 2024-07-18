/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_guide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:12:55 by fli               #+#    #+#             */
/*   Updated: 2024/07/18 11:20:04 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_guide(t_fractal *f)
{
	ft_putendl_fd("First argument : fractal name (in lowercase)", 1);
	ft_putendl_fd("- mandelbrot", 1);
	ft_putendl_fd("- julia [Re parameter] [Im parameter]", 1);
	ft_putendl_fd("/!\\ julia's parameters have to be between -1 and 1", 1);
	clean_exit(f);
}

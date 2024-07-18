/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_guide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:12:55 by fli               #+#    #+#             */
/*   Updated: 2024/07/18 18:42:17 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_guide(t_fractal *f)
{
	ft_putendl_fd("Valid arguments : fractal name (in lowercase)", 1);
	ft_putendl_fd("- mandelbrot", 1);
	ft_putendl_fd("- burningship", 1);
	ft_putendl_fd("- julia [Re parameter] [Im parameter]", 1);
	ft_putstr_fd("  /!\\ julia's parameters must follow this format :", 1);
	ft_putendl_fd(" [interger part].[fractional part]", 1);
	ft_putendl_fd("  i.e. julia −0.8 0.156", 1);
	ft_putendl_fd(" ", 1);
	ft_putendl_fd("Press C to change color", 1);
	ft_putendl_fd("Press ESC to close window", 1);
	clean_exit(f);
}

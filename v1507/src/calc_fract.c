/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:58:26 by fli               #+#    #+#             */
/*   Updated: 2024/07/15 15:18:55 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_fract(t_fractal *f, int cx, int cy)
{
	int	i;

	i = 0;
	if (f->set == 'm')
		i = mandel_calc(cx, cy);
	// else if (f->set == 'j')
	// 	i = julia_calc();
	// else if (f->set == 'b')
	// 	i = burn_calc();
	return (i);
}

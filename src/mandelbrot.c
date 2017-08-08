/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/04/10 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		iter_manloop(t_look *look)
{
	int		i;

	i = 0;
	while (i < look->maxi)
	{
		look->o_re = look->n_re;
		look->o_im = look->n_im;
		look->n_re = look->o_re * look->o_re - (look->o_im * look->o_im)
			+ look->real_p;
		look->n_im = 2 * look->o_re * look->o_im + look->imag_p;
		if ((look->n_re * look->n_re + look->n_im * look->n_im) > 4)
			break ;
		i++;
	}
	return (i);
}

int		iter_shiploop(t_look *look)
{
	int		i;

	i = 0;
	while (i < look->maxi)
	{
		look->o_re = look->n_re;
		look->o_im = look->n_im;
		look->n_re = fabs(look->o_re * look->o_re - (look->o_im * look->o_im)
			+ look->real_p);
		look->n_im = fabs(2 * look->o_re * look->o_im + look->imag_p);
		if ((look->n_re * look->n_re + look->n_im * look->n_im) > 4)
			break ;
		i++;
	}
	return (i);
}

int		iter_barloop(t_look *look)
{
	int		i;

	i = 0;
	while (i < look->maxi)
	{
		look->o_re = look->n_re;
		look->o_im = look->n_im;
		look->n_re = look->o_re * look->o_re - (look->o_im * look->o_im)
			+ look->real_p;
		look->n_im = -(2 * look->o_re * look->o_im + look->imag_p);
		if ((look->n_re * look->n_re + look->n_im * look->n_im) > 4)
			break ;
		i++;
	}
	return (i);
}

void	mandelbrot_ship(int y, t_look *look)
{
	int i;
	int x;

	x = 0;
	while (x < look->size)
	{
		look->real_p = 1.5 * (x - look->size / 2) / (0.5 * look->zoom
			* look->size) + look->move_x;
		look->imag_p = (y - look->size / 2) / (0.5 * look->zoom * look->size)
			+ look->move_y;
		look->n_re = 0;
		look->n_im = 0;
		look->o_re = 0;
		look->o_im = 0;
		if (look->map == 1)
			i = iter_manloop(look);
		else if (look->map == 3)
			i = iter_shiploop(look);
		else if (look->map == 5)
			i = iter_barloop(look);
		look->hold[x + (y * look->size)] = color_pixel(i, look);
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/04/10 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		iter_julloop(t_look *look)
{
	int		i;

	i = 0;
	while (i < look->maxi)
	{
		look->o_re = look->n_re;
		look->o_im = look->n_im;
		look->n_re = look->o_re * look->o_re - (look->o_im * look->o_im)
			+ look->c_re;
		look->n_im = 2 * look->o_re * look->o_im + look->c_im;
		if ((look->n_re * look->n_re + look->n_im * look->n_im) > 4)
			break ;
		i++;
	}
	return (i);
}

int		iter_jshiploop(t_look *look)
{
	int		i;

	i = 0;
	while (i < look->maxi)
	{
		look->o_re = look->n_re;
		look->o_im = look->n_im;
		look->n_re = fabs(look->o_re * look->o_re - (look->o_im * look->o_im)
			+ look->c_re);
		look->n_im = fabs(2 * look->o_re * look->o_im + look->c_im);
		if ((look->n_re * look->n_re + look->n_im * look->n_im) > 4)
			break ;
		i++;
	}
	return (i);
}

void	julia(int y, t_look *look)
{
	int i;
	int x;

	x = 0;
	look->real_p = 0;
	look->imag_p = 0;
	while (x < look->size)
	{
		look->n_re = 1.5 * (x - look->size / 2) / (0.5 * look->zoom
			* look->size) + look->move_x;
		look->n_im = (y - look->size / 2) / (0.5 * look->zoom * look->size)
			+ look->move_y;
		if (look->map == 2)
			i = iter_julloop(look);
		else if (look->map == 4)
			i = iter_jshiploop(look);
		look->hold[x + (y * look->size)] = color_pixel(i, look);
		x++;
	}
}

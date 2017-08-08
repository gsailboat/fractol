/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/04/10 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_scroll(t_look *look)
{
	if (look->zoom == 1)
		look->zoom *= 2;
	else if (look->zoom >= 10)
		look->zoom *= 1.25;
	else
		look->zoom *= 1.5;
}

int		scroll_key(int button, int x, int y, t_look *look)
{
	if (button == 5 && look->zoom <= (4294967295 / 1.25))
		zoom_scroll(look);
	else if (button == 4 && look->zoom >= 2)
		look->zoom /= 2;
	else if (button == 1 && look->zoom <= (4294967295 / 1.25))
	{
		zoom_scroll(look);
		look->move_x += (0.5 * (x - (look->size / 2)) /
			(look->size / 2) / look->zoom);
		look->move_y += (0.5 * (y - (look->size / 2)) /
			(look->size / 2) / look->zoom);
	}
	else if (button == 2 && look->zoom >= 2)
	{
		look->zoom /= 2;
		look->move_x += (0.5 * (x - (look->size / 2)) /
			(look->size / 2) / look->zoom);
		look->move_y += (0.5 * (y - (look->size / 2)) /
			(look->size / 2) / look->zoom);
	}
	mlx_destroy_image(look->mlx, look->img);
	setup(look);
	return (0);
}

int		mouse_key(int x, int y, t_look *look)
{
	if ((look->map == 2 || look->map == 4) && look->pause == 0)
	{
		if (x > 0 && y > 0 && x <= 599 && y <= 599)
		{
			look->c_re = (double)(x - (look->size / 2)) / (look->size / 2);
			look->c_im = (double)(y - (look->size / 2)) / (look->size / 2);
			mlx_destroy_image(look->mlx, look->img);
			setup(look);
		}
	}
	return (0);
}

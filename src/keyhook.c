/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhoook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/04/10 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	reset(t_look *look)
{
	if (look->map == 1 || look->map == 3)
		look->move_x = -0.5;
	else
		look->move_x = 0;
	if (look->map == 3)
		look->move_y = -0.5;
	else
		look->move_y = 0;
	look->zoom = 1;
	look->maxi = 90;
}

void	pause_map_key(int keycode, t_look *look)
{
	if (keycode == 35 && (look->map == 2 || look->map == 4))
		look->pause = (look->pause == 0) ? 1 : 0;
	else if (keycode == 46)
	{
		if (look->map == 5)
			look->map = 1;
		else
			look->map += 1;
		reset(look);
	}
	else if (keycode == 15)
		reset(look);
}

int		my_key(int keycode, t_look *look)
{
	if (keycode == 53)
	{
		mlx_destroy_window(look->mlx, look->win);
		exit(0);
	}
	else if (keycode == 126)
		look->move_y -= (.5 / look->zoom);
	else if (keycode == 123)
		look->move_x -= (.5 / look->zoom);
	else if (keycode == 125)
		look->move_y += (.5 / look->zoom);
	else if (keycode == 124)
		look->move_x += (.5 / look->zoom);
	else if (keycode == 8)
		look->ch_color += 1;
	else if (keycode == 1 && look->maxi >= 20)
		look->maxi -= 10;
	else if (keycode == 0 && look->maxi <= 340)
		look->maxi += 10;
	else if (keycode == 35 || keycode == 46 || keycode == 15)
		pause_map_key(keycode, look);
	mlx_destroy_image(look->mlx, look->img);
	setup(look);
	return (0);
}

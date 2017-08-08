/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/05/19 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_look *look)
{
	int			y;

	y = 0;
	while (y < look->size)
	{
		if (look->map == 1 || look->map == 3 || look->map == 5)
			mandelbrot_ship(y, look);
		else
			julia(y, look);
		y++;
	}
}

void	setup(t_look *look)
{
	int			bpp;
	int			ed;

	look->img = mlx_new_image(look->mlx, look->size, look->size);
	look->hold = (unsigned int *)mlx_get_data_addr(look->img, &bpp,
		&(look->lsize), &ed);
	draw_fractal(look);
	mlx_put_image_to_window(look->mlx, look->win, look->img, 0, 0);
}

void	struct_init(t_look *look)
{
	look->mlx = mlx_init();
	look->size = 500;
	look->maxi = 90;
	look->zoom = 1;
	look->pause = 0;
	look->move_y = 0;
	look->move_x = -0.5;
	look->ch_color = 0;
	look->c_re = -0.7;
	look->c_im = 0.27015;
	if (look->map == 2 || look->map == 5)
		look->move_x = 0;
	if (look->map == 3)
		look->move_y = -0.5;
	look->win = mlx_new_window(look->mlx, look->size, look->size, "fractol");
}

int		main(int ac, char **av)
{
	t_look	*look;

	if (ac == 2)
	{
		look = (t_look*)ft_memalloc(sizeof(t_look));
		look->map = ft_atoi(av[1]);
		if (look->map >= 1 && look->map <= 5)
		{
			struct_init(look);
			setup(look);
			mlx_hook(look->win, 2, 3, my_key, look);
			mlx_hook(look->win, 6, 0, mouse_key, look);
			mlx_hook(look->win, 4, 2, scroll_key, look);
			mlx_loop(look->mlx);
		}
		else
		{
			ft_putstr("Follow key for executable:\n1 = Mandelbrot\n");
			ft_putstr("2 = Julia\n3 = Burning Ship\n");
			ft_putstr("4 = Burning Ship Julia\n5 = Mandelbar\n");
		}
	}
	else
		ft_putstr("Need two parameters: ./fractol [number between 1 and 5]\n");
	return (0);
}

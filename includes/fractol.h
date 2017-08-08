/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/04/10 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define BLACK			0x0

typedef struct			s_look
{
	void				*mlx;
	void				*win;
	void				*img;
	double				real_p;
	double				imag_p;
	double				n_re;
	double				n_im;
	double				o_re;
	double				o_im;
	double				c_re;
	double				c_im;
	double				move_x;
	double				move_y;
	unsigned int		zoom;
	int					maxi;
	int					size;
	int					lsize;
	int					map;
	int					ch_color;
	int					pause;
	unsigned int		*hold;
}						t_look;

void					setup(t_look *look);
void					mandelbrot_ship(int y, t_look *look);
void					julia(int y, t_look *look);
int						my_key(int keycode, t_look *look);
int						scroll_key(int button, int x, int y, t_look *look);
int						mouse_key(int x, int y, t_look *look);
unsigned int			color_pixel(int i, t_look *look);

#endif

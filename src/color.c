/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/04/10 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	color_pixel(int i, t_look *look)
{
	unsigned char			one;
	unsigned char			two;
	unsigned char			three;
	unsigned int			color;

	if (i == look->maxi)
		color = BLACK;
	else
	{
		one = sin((float)i / 3) * 100;
		two = cos((float)i / 6) * 100;
		three = cos((float)i / 15.14 / 4) * 100;
		if ((look->ch_color > 0 && look->ch_color % 5 == 0)
			|| look->ch_color == 0)
			color = (three << 0) | (one << 8);
		else if (look->ch_color % 5 == 1)
			color = (two << 8) | (one << 16);
		else if (look->ch_color % 5 == 2)
			color = (one << 0) | (two << 16);
		else if (look->ch_color % 5 == 3)
			color = (two << 0) | (one << 8) | (three << 16);
		else
			color = (one << 0) | (two << 8) | (three << 16);
	}
	return (color);
}

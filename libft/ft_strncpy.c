/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:49:50 by gselbo            #+#    #+#             */
/*   Updated: 2016/12/02 17:23:13 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(const char *dest, char *src, size_t n)
{
	size_t		i;
	char		*d;

	i = 0;
	d = (char*)dest;
	while (i < n && src[i])
	{
		d[i] = src[i];
		i++;
	}
	if (n > 0)
		while (i < n)
		{
			d[i] = '\0';
			i++;
		}
	return (d);
}

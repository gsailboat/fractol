/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 20:29:22 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/28 21:16:11 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s;
	b = (unsigned char *)d;
	while (i < n)
	{
		b[i] = a[i];
		if (a[i] == (unsigned char)c)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}

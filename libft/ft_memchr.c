/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:10:46 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/30 13:47:21 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char*)s;
	while (i < n)
	{
		if (a[i] == (unsigned char)c)
			return ((void*)&a[i]);
		i++;
	}
	return (NULL);
}

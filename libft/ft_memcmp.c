/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:56:01 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/21 17:48:57 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *d, const void *s, size_t n)
{
	const unsigned char *s1;
	const unsigned char *s2;

	s1 = d;
	s2 = s;
	while (n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		else
		{
			s1++;
			s2++;
		}
		n--;
	}
	return (0);
}

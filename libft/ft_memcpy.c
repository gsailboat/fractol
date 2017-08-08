/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:01:50 by gselbo            #+#    #+#             */
/*   Updated: 2016/12/02 17:42:45 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t		i;
	char		*a;
	char		*b;

	i = 0;
	a = (char*)d;
	b = (char*)s;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (d);
}

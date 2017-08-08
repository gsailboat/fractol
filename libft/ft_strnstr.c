/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:26:16 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/28 21:32:15 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		l;

	l = ft_strlen(s2);
	if (s2 == NULL || l == 0)
		return ((char *)s1);
	while (*s1 != '\0' && n-- >= l)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, l) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:34:46 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/29 20:20:39 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;
	int		i;

	str = (char *)s;
	i = 0;
	if (str[i] != '\0')
	{
		len = ft_strlen(str);
		while (i < len)
		{
			i++;
			str++;
		}
		while (i >= 0)
		{
			if (str[0] == (char)c)
				return (str);
			str--;
			i--;
		}
	}
	return (NULL);
}

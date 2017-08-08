/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:04:33 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/28 21:22:47 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*s;

	i = 0;
	s = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (s == NULL)
		return (NULL);
	ft_strcpy(s, src);
	return (s);
}

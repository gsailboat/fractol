/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:55:06 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/28 21:43:19 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*join;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (*s1)
		join[++i] = *s1++;
	while (*s2)
		join[++i] = *s2++;
	join[++i] = '\0';
	return (join);
}

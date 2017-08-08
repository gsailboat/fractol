/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:53:05 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/28 21:51:23 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*n;

	i = 0;
	n = (char *)s;
	if (s == NULL || f == NULL)
		return (NULL);
	n = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (n == NULL)
		return (NULL);
	while (s[i])
	{
		n[i] = (*f)(i, s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}

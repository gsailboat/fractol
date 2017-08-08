/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:16:45 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/28 21:50:49 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*n;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	n = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (n == NULL)
		return (NULL);
	while (s[i])
	{
		n[i] = (*f)(s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}

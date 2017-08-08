/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:46:26 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/28 21:33:35 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	i = 0;
	sub = (char*)malloc(sizeof(char) * (len + 1));
	if (s != NULL && sub != NULL)
	{
		while (len--)
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	else
		return (NULL);
	sub[i] = '\0';
	return (sub);
}

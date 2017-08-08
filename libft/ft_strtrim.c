/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:47:03 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/29 20:09:47 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_space(char *s)
{
	size_t	i;
	size_t	sp;
	size_t	l;

	l = ft_strlen(s);
	i = 0;
	sp = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	sp = i;
	if (s[i] != '\0')
	{
		i = l - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			sp++;
		}
	}
	return (l - sp);
}

char			*ft_strtrim(char const *s)
{
	char	*a;
	size_t	i;
	size_t	j;
	size_t	spf;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	spf = find_space((char*)s);
	a = (char*)malloc(sizeof(char) * (spf + 1));
	if (a == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < spf)
	{
		a[j] = s[i];
		j++;
		i++;
	}
	a[j] = '\0';
	return (a);
}

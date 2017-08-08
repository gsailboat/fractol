/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:11:56 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/29 20:10:23 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_comp(const char *s, char c)
{
	int	a;
	int b;

	a = 0;
	b = 0;
	while (*s != '\0')
	{
		if (b == 1 && *s == c)
			b = 0;
		if (b == 0 && *s != c)
		{
			b = 1;
			a++;
		}
		s++;
	}
	return (a);
}

static int			ft_wlen(const char *s, char c)
{
	int l;

	l = 0;
	while (*s != c && *s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		n;
	char	**p;

	i = 0;
	if (!s)
		return (0);
	n = ft_comp((const char *)s, c);
	p = (char **)malloc(sizeof(*p) * (n + 1));
	if (p == NULL)
		return (NULL);
	while (n--)
	{
		while (*s == c && *s != '\0')
			s++;
		p[i] = ft_strsub((const char *)s, 0, ft_wlen((const char *)s, c));
		if (p[i] == NULL)
			return (NULL);
		s = s + ft_wlen(s, c);
		i++;
	}
	p[i] = NULL;
	return (p);
}

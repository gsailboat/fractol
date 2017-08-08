/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 20:51:18 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/29 20:14:57 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		digits(long n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*a;
	int		l;
	long	t;

	t = (long)n;
	if (n < 0)
	{
		t *= -1;
		l = digits(n) + 1;
	}
	else
		l = digits(n);
	if (!(a = ft_strnew(l)))
		return (NULL);
	l--;
	if (t == 0)
		a[0] = '0';
	while (t != 0)
	{
		a[l--] = (t % 10) + '0';
		t /= 10;
	}
	if (n < 0)
		a[0] = '-';
	return (a);
}

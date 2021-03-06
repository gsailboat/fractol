/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 20:17:45 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/28 21:44:01 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	char	*s;
	int		ans;
	int		pon;

	ans = 0;
	pon = 1;
	s = (char*)str;
	while (*s == '\t' || *s == '\f' || *s == ' ' || *s == '\r' || *s == '\v'
			|| *s == '\n')
		s++;
	if (*s == '-')
		pon = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s != '\0' && (*s >= '0') && (*s <= '9'))
	{
		ans = ans * 10 + *s - '0';
		s++;
	}
	ans = ans * pon;
	return (ans);
}

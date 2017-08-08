/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:57:49 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/29 21:00:26 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fibonacci(int i)
{
	if (i < 0)
		return (-1);
	else if (i == 0)
		return (0);
	else if (i == 1)
		return (1);
	else
		return (ft_fibonacci(i - 1) + ft_fibonacci(i - 2));
	return (i);
}

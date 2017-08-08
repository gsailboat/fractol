/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:23:39 by gselbo            #+#    #+#             */
/*   Updated: 2016/11/28 21:11:51 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*now;
	t_list	*end;
	t_list	*beg;

	beg = NULL;
	while (f && lst)
	{
		end = malloc(sizeof(t_list));
		if (!end)
			return (NULL);
		end = f(lst);
		if (!beg)
		{
			beg = end;
			now = end;
		}
		else
		{
			now->next = end;
			now = now->next;
		}
		lst = lst->next;
	}
	return (beg);
}

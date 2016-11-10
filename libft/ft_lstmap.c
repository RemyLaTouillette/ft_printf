/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 09:29:51 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:40:16 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *begin;

	begin = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		tmp = f(lst);
		if (!begin)
			begin = tmp;
		else
			ft_lstend(begin)->next = tmp;
		lst = lst->next;
	}
	return (begin);
}

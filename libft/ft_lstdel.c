/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 07:40:20 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:41:28 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	lst = *alst;
	while (lst->next)
	{
		del(lst->content, lst->content_size);
		lst = lst->next;
	}
	free(lst);
	*alst = NULL;
}

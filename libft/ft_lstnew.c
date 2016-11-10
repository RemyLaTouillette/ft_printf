/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 23:44:02 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:40:06 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*ccpy;

	lst = (t_list *)malloc(sizeof(t_list));
	ccpy = (void *)malloc(content_size);
	if (!lst || !ccpy)
		return (NULL);
	if (!content || !content_size)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content = ft_memcpy(ccpy, content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}

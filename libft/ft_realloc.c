/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 07:34:57 by sduprey           #+#    #+#             */
/*   Updated: 2015/02/18 05:15:28 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*p_ptr;

	if (!ptr)
		return (ft_memalloc(size));
	if (!size)
		return (ptr);
	if (!(p_ptr = ft_memalloc(size)))
		return (ptr);
	ft_memcpy(p_ptr, ptr, size);
	free(ptr);
	ptr = NULL;
	return (p_ptr);
}

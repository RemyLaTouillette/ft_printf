/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:44:56 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:40:26 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void *new;

	new = malloc(sizeof(void *) * size);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}

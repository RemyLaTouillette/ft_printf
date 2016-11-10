/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.2.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:02:48 by sduprey           #+#    #+#             */
/*   Updated: 2014/11/12 03:33:15 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	i;

	len_dst = ft_strlen(dst);
	i = 0;
	if (size >= len_dst)
	{
		while (len_dst < size - 1)
			dst[len_dst++] = src[i++];
		dst[len_dst] = '\0';
		return (len_dst + ft_strlen(src) - i);
	}
	return (size + ft_strlen(src));
}

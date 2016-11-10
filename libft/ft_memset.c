/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:25:56 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:37:20 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*uc;

	if (len && b)
	{
		uc = (unsigned char *)b;
		i = 0;
		while (i < len)
			uc[i++] = (unsigned char)c;
	}
	return (b);
}

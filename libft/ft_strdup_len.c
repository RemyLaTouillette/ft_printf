/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:10:47 by sduprey           #+#    #+#             */
/*   Updated: 2015/01/04 21:37:34 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup_len(const char *s1, size_t len)
{
	char	*ret;

	if (!(ret = (char*)ft_memalloc((len + 1) * sizeof(char))))
		return (0);
	ret = ft_strncpy(ret, s1, len);
	return (ret);
}

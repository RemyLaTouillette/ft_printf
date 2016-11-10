/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:16:59 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:31:17 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (s2[0] == '\0')
		return ((char *)s1);
	if (ft_strlen(s2) > n)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0' || i < n)
	{
		while (s1[i] == s2[j] && s1[i] != '\0' && i < n)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)&s1[i - j]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}

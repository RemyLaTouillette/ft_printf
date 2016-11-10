/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 01:09:46 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:31:00 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*trimend(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		str[i--] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	str = ft_strsub(s, i, ft_strlen(s));
	str = trimend(str);
	return (str);
}

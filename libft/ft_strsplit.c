/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 22:16:10 by sduprey           #+#    #+#             */
/*   Updated: 2015/03/21 22:19:51 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		height(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int		lenght(const char *s, int i, int len, char c)
{
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char		*prt(char const *s, char c, int i, char *str)
{
	int j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	int				x;
	int				y;

	i = 0;
	x = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (height(s, c) + 1));
	while (s[i] != '\0' && i < ft_strlen(s))
	{
		y = 0;
		if (s[i] != c)
		{
			y = lenght(s, i, y, c);
			tab[x] = (char *)malloc(sizeof(char) * (y + 1));
			tab[x] = prt(s, c, i, tab[x]);
			i = i + y - 1;
			x++;
		}
		i++;
	}
	tab[x] = 0;
	return (tab);
}

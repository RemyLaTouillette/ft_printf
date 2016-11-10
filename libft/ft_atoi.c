/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:32:51 by sduprey           #+#    #+#             */
/*   Updated: 2014/11/12 07:28:42 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	is_char_to_escape(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r' ||
			c == '\f')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int is_negative;
	int value;

	is_negative = 0;
	value = 0;
	i = 0;
	while (is_char_to_escape(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		value = (value * 10) - (str[i] - '0');
		i++;
	}
	if (!is_negative)
		value *= -1;
	return (value);
}

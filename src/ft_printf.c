/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:01:40 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/12 19:01:33 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	t_pf	*start;

	start = parse_input(str);
	va_start(ap, str);
	i = 0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:01:40 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 17:33:24 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		isarg(int i, char *str)
{
	if (str[i] == '%')
	{
		if (i == 0 && str[i + 1] != '\0' && str[i + 1] != '%')
			return (1);
	}
	return (0);
}


int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
//	int		nb_occ; //how many % whitout %%
	t_pf	*start;

	start = parse_input(str);
	


	/*
	tab = ft_strsplit(str, '%');
	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
	*/

	va_start(ap, str);
	i = 0;
	/*
	while (str[i] != '\0')
	{
		if (isarg(i, str))
		{
			ft_putendl(str + i);
		}
		ft_putchar(str[i]);
		i++;
	}
	*/
	return (0);
}

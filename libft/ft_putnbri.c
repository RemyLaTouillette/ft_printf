/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 23:04:50 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:33:45 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbri(int nbr)
{
	int tmp;
	int chiffre;
	int size;

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	tmp = nbr;
	size = 1;
	while (tmp / 10 > 0)
	{
		size = size * 10;
		tmp = tmp / 10;
	}
	while (size > 0)
	{
		chiffre = 0;
		chiffre = nbr / size;
		ft_putchar('0' + chiffre);
		nbr = nbr % size;
		size = size / 10;
	}
}

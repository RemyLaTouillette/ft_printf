/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:06:52 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:36:27 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbro(int n, int zero)
{
	unsigned int nbr;

	if (!zero)
	{
		zero = 1;
		ft_putchar('0');
	}
	if (n < 0)
	{
		nbr = n * -1;
		ft_putchar('-');
	}
	else
		nbr = n;
	if (nbr > 10)
	{
		ft_putnbro(nbr / 10, zero);
		ft_putnbro(nbr % 10, zero);
	}
	else
		ft_putchar(nbr + '0');
}

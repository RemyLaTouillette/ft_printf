/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basenbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 06:53:55 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:39:38 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_basenbr(int n, int base)
{
	int i;
	int nbase;

	i = 0;
	nbase = 0;
	while (n > 0)
	{
		nbase += (n % base) * ft_pow(10, i);
		n /= base;
		i++;
	}
	return (nbase);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 06:53:55 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:43:08 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itob(int n)
{
	int		i;
	int		b;
	char	*bin;

	bin = (char *)malloc(sizeof(char) * 13);
	i = 11;
	while (i >= 0)
	{
		if (n >= 0)
		{
			b = n % 2;
			n /= 2;
			bin[i] = b + '0';
		}
		else
			bin[i] = 0;
		i--;
	}
	bin[12] = '\0';
	return (bin);
}

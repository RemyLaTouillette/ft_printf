/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:59:41 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 16:30:13 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>

# include <stdarg.h>

typedef struct	s_pf
{
	char		*sub;
	char		*flag; // '\0', -, +, #, ' '
	int			length;

	int			preci;
	int			ispreci;

	int			lpad;
	int			rpad;
	char		pad;

	char		modif; // h H(hh) l L(ll) j z

	char		format; // sSpdDiouUxXcC
}				t_pf;

int				ft_printf(char *str, ...);

#endif

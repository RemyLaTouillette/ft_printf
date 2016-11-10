/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:59:41 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 17:54:41 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>

# include <stdarg.h>

// "salut les %s ! %dede %i"

typedef struct	s_pf
{
	size_t		content_size;
	char		*sub;
	char		*flag; // '0', -, +, #, ' '
	int			length;

	int			preci;
	int			ispreci;

	int			lpad;
	int			rpad;
	char		pad;

	char		modif; // h H(hh) l L(ll) j z

	char		format; // sSpdDiouUxXcC
	struct s_pf	*nxt;
}				t_pf;

int				ft_printf(char *str, ...);
t_pf			*parse_input(char *str);
t_pf			*pf_new(void const *content, size_t content_size);

#endif

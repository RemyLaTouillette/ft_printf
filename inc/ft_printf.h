/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:59:41 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/12 19:07:56 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>
# include <stdio.h>

// "salut les %s ! %dede %i"

typedef struct		s_pf
{
	size_t		content_size;
	char		*sub;
	char		*flag; // '0', -, +, #, ' '
	int		length;

	int		preci;
	int		ispreci;

	int		lpad;
	int		rpad;
	int		padvalue;
	char		pad;

	char		*modif; // h H(hh) l L(ll) j z

	char		*format; // sSpdDiouUxXcC
	struct s_pf	*nxt;
}			t_pf;

int			ft_printf(char *str, ...);

/*list.c*/
t_pf			*pf_new(void const *content, size_t content_size);
void			free_lst(t_pf *lst);

/*get_val.c*/
int			get_pad_value(char *s, int *i);
int			get_preci(char *s, int *i, int *ispreci);
char			*get_flag(char *s, int *i);
char			*get_modif(char *s, int *i);
char			*get_format(char *s, int *i);

/*parse.c*/
void			display(t_pf *l);
void			fill_struct(t_pf *l);
t_pf			*next_occ(char *s, int *i);
t_pf			*basic_split(char *str);
t_pf			*parse_input(char *str);

/*exception.c*/
void			handle_exce(t_pf *lst);


#endif

#include <ft_printf.h>


t_pf		*next_occ(char *s, int *i)
{
	t_pf	*rtn;
	char	*tmpstr;
	int	start;
	int	end;

	start = *i;
	rtn = NULL;
	if (s && s[start] != '\0')
	{
		end = start + 1;
		while (s[end] != '\0' && s[end] == '%')
			end++;
		while (s[end] != '\0' && s[end] != '%')
			++end;
		tmpstr = ft_strsub(s, start, (end - start));
		rtn = pf_new(tmpstr, ft_strlen(tmpstr) + 1);
		free(tmpstr);
		*i = end;
	}
	else
		*i = -1;
	return (rtn);
}

t_pf		*noform(t_pf *l, int i)
{
	char	*first;
	char	*second;
	t_pf	*newnext;
	t_pf	*tmp;

	first = ft_strsub(l->sub, 0, i);
	second = ft_strsub(l->sub,i, ft_strlen(l->sub));
	free(l->sub);
	l->sub = first;
	newnext = pf_new(second, ft_strlen(second) + 1);
	free(second);
	tmp = l->nxt;
	l->nxt = newnext;
	newnext->nxt = tmp;
	return (l->nxt);
}

void		fill_struct(t_pf *l, va_list ap)
{
	int		index;

	while (l)
	{
		if (l->sub && l->sub[0] == '%')
		{
			index = 1;
			l->flag = get_flag(l->sub, &index);
			l->padvalue = get_pad_value(l->sub, &index);
			l->preci = get_preci(l->sub, &index, &l->ispreci);
			l->modif = get_modif(l->sub, &index);
			l->format = get_format(l->sub, &index);
			printf("[GET FORMAT] => |%c|\n",l->format);
			l->val = get_val(ap, l->format);
			l = ((int)ft_strlen(l->sub) > index) ? noform(l, index) : l;
		}
		l = l->nxt;
	}
}

t_pf		*basic_split(char *str)
{
	t_pf	*hd;
	t_pf	*tmp;
	int	i;
	int	len;

	i = 0;
	hd = NULL;
	len = strlen(str);
	if (len > 0)
	{
		hd = next_occ(str, &i);
		tmp = hd;
		while (i != -1)
		{
			tmp->nxt = next_occ(str, &i);
			tmp = tmp->nxt;
		}
	}
	return (hd);
}

t_pf		*parse_input(char *str, va_list ap)
{
	t_pf	*hd;

	printf("INPUT|%s|\n",str);
	hd = basic_split(str);
	fill_struct(hd, ap);
	display(hd);
	return (hd);
}

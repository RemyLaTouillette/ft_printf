#include <ft_printf.h>

int			get_pad_value(char *s, int *i)
{
	int		rtn;
	int		index;
	char	*tmp;

	rtn = 0;
	index = *i;
	while (s[index] && s[index] != '\0' && ft_isdigit(s[index]))
		index++;
	if (index == *i)
		return (0);
	tmp = ft_strnew(index + 1);
	tmp[index] = '\0';
	index = *i;
	while (s[index] && s[index] != '\0' && ft_isdigit(s[index]))
	{
		tmp[rtn] = s[index];
		index++;
		rtn++;
	}
	*i = index;
	rtn = ft_atoi(tmp);
	free(tmp);
	return (rtn);
}

char		*get_flag(char *s, int *i)
{
	char	*rtn;
	int	index;
	int	rtn_i;

	index = *i;
	rtn_i = 0;
	while (s[index] && s[index] != '\0' && ft_strchr("0-+# ", s[index]))
		index++;
	rtn = ft_strnew(index);
	index = *i;
	while (s[index] && s[index] != '\0' && ft_strchr("0-+# ", s[index]))
	{
		rtn[rtn_i] = s[index];
		rtn_i++;
		index++;
	}
	rtn[rtn_i] = '\0';
	if (index == *i)
	{
		free(rtn);
		return (NULL);
	}
	*i = index;
	return (rtn);
}

int		get_preci(char *s, int *i, int *ispreci)
{
	int	rtn;
	int	index;
	char	*tmp;

	rtn = 0;
	index = *i;
	if (s[index] == '.')
	{
		index++;
		while (s[index] && s[index] != '\0' && ft_isdigit(s[index]))
			index++;
		if (index == *i)
			return (0);
		tmp = ft_strnew(index + 1);
		tmp[index] = '\0';
		index = *i + 1;
		while (s[index] && s[index] != '\0' && ft_isdigit(s[index]))
		{
			tmp[rtn] = s[index];
			index++;
			rtn++;
		}
		rtn = ft_atoi(tmp);
		free(tmp);
		*ispreci = 1;
		*i += index - 1;
		return (rtn);
	}
	*ispreci = 0;
	return (0);
}

char			*get_modif(char *s, int *i)
{
	char		*rtn;
	int		index;
	int		rtn_i;

	index = *i + 1;
	rtn_i = 0;
	while (s[index] != '\0' && ft_strchr("hljz", s[index]))
		index++;
	rtn = ft_strnew((index - *i) + 1);
	index = *i;
	while (s[index] != '\0' && ft_strchr("hljz", s[index]))
	{
		rtn[rtn_i] = s[index];
		rtn_i++;
		index++;
	}
	rtn[rtn_i] = '\0';
	if (index == *i)
	{
		free(rtn);
		return (NULL);
	}
	*i = index;
	return (rtn);
}

char			get_format(char *s, int *i)
{
	char		rtn;

	rtn = (char)malloc(sizeof(char));
	if (s[*i] != '\0' && ft_strchr("sSpdDiouUxXcC", s[*i]))
	{
		rtn = s[*i];
		*i = *i + 1;
	}
	else
		rtn = ' ';
	return (rtn);
}

void			*get_val(va_list ap, char format)
{
	t_form		*pf;
	int			tablen;
	void		*rtn;

	rtn = NULL;
	pf = createArray(&tablen);
	while (tablen--)
		if (pf[tablen].flag && pf[tablen].flag == format)
			rtn = pf[tablen].func(ap);
	if (format == 's')
	{
		ft_putstr("[GET_VAL]");
		if (rtn != NULL)
			ft_putstr((char *)rtn);
		ft_putstr("\n");
	}
	return rtn;
}


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
	int		index;
	int		rtn_i;

	index = *i;
	rtn = ft_strnew(6);
	rtn_i = 0;
	while (s[index] && s[index] != '\0' && ft_strchr("0-+# ", s[index]) != NULL)
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

int			get_preci(char *s, int *i, int *ispreci)
{
	int		rtn;
	int		index;
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
		return (rtn);
	}
	*ispreci = 0;
	return (0);
}

char		*get_modif(char *s, int *i)
{
	char	*rtn;
	int		index;
	int		rtn_i;

	index = *i + 1;
	rtn_i = 0;
	while (s[index] && s[index] != '\0' && ft_strchr("hljz", s[index]) != NULL)
		index++;
	rtn = ft_strnew((index - *i) + 1);
	index = *i;
	while (s[index] && s[index] != '\0' && ft_strchr("hljz", s[index]) != NULL)
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

char		*get_format(char *s, int *i)
{
	char	*rtn;
	int		index;
	int		rtn_i;

	index = *i + 1;
	rtn_i = 0;
	while (s[index] && s[index] != '\0' && \
			ft_strchr("sSpdDiouUxXcC", s[index]) != NULL)
		index++;
	rtn = ft_strnew((index - *i) + 1);
	index = *i;
	while (s[index] && s[index] != '\0' && \
			ft_strchr("sSpdDiouUxXcC", s[index]) != NULL)
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

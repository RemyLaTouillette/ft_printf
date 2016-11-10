/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 06:04:01 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/10 12:32:10 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	check_save(char *buf, char **tmp, char *save)
{
	int i;
	int j;

	i = ft_strlen(*tmp);
	j = 0;
	*tmp = ft_realloc(*tmp, (ft_strlen(*tmp) + ft_strlen(buf) + 1));
	while (buf[j] != '\0')
	{
		if (buf[j] == '\n')
		{
			*((*tmp) + i) = '\0';
			save = ft_strcpy(save, &buf[++j]);
			return (1);
		}
		tmp[0][i++] = buf[j++];
	}
	ft_bzero(save, ft_strlen(save));
	*((*tmp) + i) = '\0';
	return (0);
}

static int	free_and_return(char **buf, char **tmp, char **line, int ret)
{
	*line = ft_strdup(*tmp);
	free(*buf);
	*buf = NULL;
	free(*tmp);
	*tmp = NULL;
	return (ret);
}

static void	free_and_free(char **buf, char **tmp)
{
	free(*buf);
	*buf = NULL;
	free(*tmp);
	*tmp = NULL;
}

int			get_next_line(int const fd, char **line)
{
	int			ret;
	char		*buf;
	char		*tmp;
	static char save[BUFF_SIZE];

	if (fd == -1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (tmp == NULL || buf == NULL)
		return (-1);
	if (check_save(save, &tmp, save) == 1)
		return (free_and_return(&buf, &tmp, line, 1));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (check_save(buf, &tmp, save) == 1)
			return (free_and_return(&buf, &tmp, line, 1));
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && buf[0] != '\0')
		return (free_and_return(&buf, &tmp, line, 1));
	free_and_free(&buf, &tmp);
	return (0);
}

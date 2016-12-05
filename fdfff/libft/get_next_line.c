/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:01:13 by behamon           #+#    #+#             */
/*   Updated: 2016/11/24 13:37:56 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

static int	read_and_update(const int fd, char **str)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
		return (-1);
	buf[ret] = '\0';
	if (ret > 0)
	{
		if (!(tmp = ft_strjoin(*str, buf)))
			return (-1);
		free(*str);
		*str = tmp;
	}
	return (ret);
}

static int	fill_and_move(char **line, char **endl_pos, char **str)
{
	*line = ft_strsub(*str, 0, *endl_pos - *str);
	*endl_pos = ft_strdup(*endl_pos + 1);
	free(*str);
	*str = *endl_pos;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str;
	int			ret;
	char		*endl_pos;

	if (fd < 0 || !line)
		return (-1);
	if (!str)
		str = ft_strnew(0);
	endl_pos = ft_strchr(str, '\n');
	while (endl_pos == NULL)
	{
		if ((ret = read_and_update(fd, &str)) == 0)
		{
			if ((endl_pos = ft_strchr(str, '\0')) == str)
			{
				*line = NULL;
				return (0);
			}
		}
		else if (ret == -1)
			return (-1);
		else
			endl_pos = ft_strchr(str, '\n');
	}
	return (fill_and_move(line, &endl_pos, &str));
}

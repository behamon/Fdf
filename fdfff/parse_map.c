/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:03:36 by behamon           #+#    #+#             */
/*   Updated: 2016/12/05 18:25:26 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	count_file_lines(int fd)
{
	char	*line;
	size_t	n_lines;

	n_lines = 0;
	if (fd > 0)
	{
		while ((get_next_line(fd, &line)) == 1)
			n_lines++;
		ft_strdel(&line);
	}
	return (n_lines);
}

int		*fill_int_map_lines(char *line)
{
	char	**tab;
	int		*map_line;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[len])
		len++;
	if (!(map_line = (int*)malloc(sizeof(int) * len + 1)))
		return (0);
	while (*tab)
	{
		map_line[i] = ft_atoi(*tab);
		i++;
		tab++;
	}
	map_line[i] = TAB_STOP;
	return (map_line);
}

int		*fill_last_line(size_t x_max)
{
	int		*map_line;
	size_t	i;

	i = 0;
	if (!(map_line = (int*)malloc(sizeof(int) * x_max)))
		return (0);
	while (i < x_max)
	{
		map_line[i] = TAB_STOP;
		i++;
	}
	map_line[i] = TAB_STOP;
	return (map_line);
}

int		**fill_int_map(int fd, size_t n_lines)
{
	int		**map;
	char	*line;
	size_t	i;

	i = 0;
	if (!(map = (int**)malloc(sizeof(int*) * n_lines + 1)))
		return (0);
	while ((get_next_line(fd, &line)) == 1)
	{
		map[i] = fill_int_map_lines(line);
		i++;
	}
	map[i] = fill_last_line(x_len(map, n_lines));
	return (map);
}

int		main(int ac, char **av)
{
	int		fd;
	int		**map;
	size_t	n_lines;

	if (ac != 2)
		ft_putendl("usage: ./fdf <input_file>");
	else if (ac == 2)
	{
		n_lines = 0;
		if (!(fd = open(av[1], O_RDONLY)))
			return (0);
		n_lines = count_file_lines(fd);
		close(fd);
		if (!(fd = open(av[1], O_RDONLY)))
			return (0);
		map = fill_int_map(fd, n_lines);
		close(fd);
		fdf_init(map, n_lines);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:04:32 by behamon           #+#    #+#             */
/*   Updated: 2016/12/12 14:30:49 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	count_file_lines(int fd)
{
	char	*line;
	size_t	n_lines;
	int		i;

	n_lines = 0;
	i = 0;
	if (fd > 0)
	{
		while ((get_next_line(fd, &line)) == 1)
			n_lines++;
	}
	return (n_lines);
}

static size_t	empty_check(int fd)
{
	int		ret;
	char	buf[1];

	if ((ret = read(fd, buf, 1)) <= 0)
		return (0);
	return (1);
}

static int		fdf_launcher(int fd, const char *file)
{
	size_t	n_lines;
	int		**map;

	n_lines = count_file_lines(fd);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (!empty_check(fd))
		return (0);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	if (!(map = fill_int_map(fd, n_lines)))
		return (0);
	close(fd);
	fdf_init(map, n_lines);
	return (1);
}

int				main(int ac, const char **av)
{
	int		fd;

	if (ac != 2)
		ft_putendl("usage: ./fdf <input_file>");
	else
	{
		if (!(fd = open(av[1], O_RDONLY)))
			return (0);
		if (fd > 0)
		{
			if (!fdf_launcher(fd, av[1]))
				ft_putendl_fd("File error.", 2);
		}
		else
			ft_putendl_fd("File is invalid or does not exist.", 2);
	}
	return (0);
}

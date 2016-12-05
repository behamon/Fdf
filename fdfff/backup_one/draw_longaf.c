/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:16:52 by behamon           #+#    #+#             */
/*   Updated: 2016/12/01 17:43:28 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		draw_line(t_env *e)
{
	double	dx;
	double	dy;
	double	temp;
	double	x1;
	double	y1;

	x1 = e->x1;
	y1 = e->y1;
	dx = e->x2 - x1;
	dy = e->y2 - y1;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		put_pixel_to_image(x1, y1, e);
		x1 += dx;
		y1 += dy;
		temp--;
	}
	return (0);
}

void	draw_line_height(t_env *e, size_t j, int z)
{
	if (j == e->x_max - 2)
	{
		e->x1 += e->scale;
		e->x2 += e->scale;
		e->y2 += e->scale;
		e->y2 -= z;
		e->x2 -= (e->scale / 2);
		draw_line(e);
		e->y2 += z;
		e->x2 += (e->scale / 2);
		e->x2 -= e->scale;
		e->x1 -= e->scale;
		e->y2 -= e->scale;
	}
	e->y2 += e->scale;
	e->x2 -= (e->scale / 2);
	e->y2 -= z;
	draw_line(e);
	e->y2 += z;
	e->y2 -= e->scale;
	e->x2 += (e->scale / 2);
}

void	draw_line_width(t_env *e, size_t i, int z)
{
	if (i == e->y_max - 2)
	{
		e->y1 += e->scale;
		e->y2 = e->y1;
		e->x2 += e->scale;
		e->x1 -= (e->scale / 2);
		e->x2 -= (e->scale / 2);
		draw_line(e);
		e->x1 += (e->scale / 2);
		e->x2 += (e->scale / 2);
		e->x2 -= e->scale;
		e->y1 -= e->scale;
		e->y2 -= e->scale;
	}
	e->x2 += e->scale;
	draw_line(e);
	e->x1 += e->scale;
}

void	draw_map(t_env *e)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < e->y_max - 1)
	{
		e->x1 = WIDTH / 3 - ((e->scale / 2) * i);
		e->x2 = WIDTH / 3 - ((e->scale / 2) * i);
		while (j < e->x_max - 1)
		{
			draw_line_height(e, j, e->map[i][j]);
			draw_line_width(e, i, e->map[i][j]);
			j++;
		}
		e->y1 += e->scale;
		e->y2 += e->scale;
		j = 0;
		i++;
	}
	e->y1 = HEIGHT / 3;
	e->y2 = HEIGHT / 3;
}

int		image_operations(t_env *e)
{
	int		bpp;
	int		size_line;
	int		endian;

	e->image = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img_data = mlx_get_data_addr(e->image, &bpp, &size_line, &endian);
	e->scale = 30;
	draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	mlx_destroy_image(e->mlx, e->image);
	return (0);
}

int		fdf_init(int **map, size_t y_max)
{
	t_env	*e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (0);
	e->map = map;
	e->y_max = y_max;
	e->x_max = x_len(map, y_max);
	e->y1 = HEIGHT / 3;
	e->y2 = HEIGHT / 3;
	if (!(e->mlx = mlx_init()))
		return (0);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "behamon - fdf");
	mlx_key_hook(e->win, kill_win, e);
	mlx_loop_hook(e->mlx, image_operations, e);
	mlx_loop(e->mlx);
	return (0);
}

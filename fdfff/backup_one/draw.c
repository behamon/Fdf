/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:16:52 by behamon           #+#    #+#             */
/*   Updated: 2016/12/01 14:36:32 by behamon          ###   ########.fr       */
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

void	set_coordinates(t_env *e, int x, int y, int bas)
{
	e->x1 = WIDTH / 3;
	e->x2 = WIDTH / 3;
	if (bas)
	{
		e->y2 += e->scale;
	}
	else
	{
		e->x2 += e->scale;
	}
}

void	draw_map(t_env *e)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < e->y_max - 1)
	{
		while (x < e->x_max - 1)
		{
			draw_line_up(e);
			drset_coordinates(e, x, y, 0);
			draw_line(e);
			x++;
		}
		x = 1;
		y++;
	}
}

int		image_operations(t_env *e)
{
	int		bpp;
	int		size_line;
	int		endian;

	e->image = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img_data = mlx_get_data_addr(e->image, &bpp, &size_line, &endian);
	e->scale = 30;
	e->x1 = WIDTH / 3;
	e->y1 = HEIGHT / 3;

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
	if (!(e->mlx = mlx_init()))
		return (0);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "behamon - fdf");
	mlx_key_hook(e->win, kill_win, e);
	mlx_loop_hook(e->mlx, image_operations, e);
	mlx_loop(e->mlx);
	return (0);
}

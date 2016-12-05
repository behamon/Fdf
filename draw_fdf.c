/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:53:04 by behamon           #+#    #+#             */
/*   Updated: 2016/12/05 19:06:01 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_line(t_env *e, int x, int y)
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
		put_pixel_to_image(x1, y1, e, get_color(e, x, y));
		x1 += dx;
		y1 += dy;
		temp--;
	}
	return (0);
}

void	set_coordinates(t_env *e, int x, int y, int bas)
{
	int		xt;
	int		yt;

	xt = x - e->x_max / 2;
	yt = y - e->y_max / 2;
	e->x1 = (xt - yt) * e->scale + 150;
	e->y1 = 0.5 * (xt + yt) * e->scale - 250;
	e->y1 -= e->map[y][x] * e->z_scale;
	if (bas)
	{
		e->x2 = ((xt + 1) - yt) * e->scale + 150;
		e->y2 = 0.5 * ((xt + 1) + yt) * e->scale - 250;
		e->y2 -= e->map[y][x + 1] * e->z_scale;
	}
	else
	{
		e->x2 = (xt - (yt + 1)) * e->scale + 150;
		e->y2 = 0.5 * (xt + (yt + 1)) * e->scale - 250;
		e->y2 -= e->map[y + 1][x] * e->z_scale;
	}
	e->x1 += HEIGHT / 2 + 150;
	e->x2 += HEIGHT / 2 + 150;
	e->y1 += WIDTH / 2 - 250;
	e->y2 += WIDTH / 2 - 250;
}

void	draw_map(t_env *e)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y++ != e->y_max)
	{
		while (x++ != e->x_max)
		{
			if (x + 1 < e->x_max && e->map[y][x] != TAB_STOP
					&& e->map[y][x + 1] != TAB_STOP)
			{
				set_coordinates(e, x, y, 1);
				draw_line(e, x, y);
			}
			if (y + 1 < e->y_max && e->map[y][x] != TAB_STOP
					&& e->map[y + 1][x] != TAB_STOP)
			{
				set_coordinates(e, x, y, 0);
				draw_line(e, x, y);
			}
		}
		x = 0;
	}
}

int		image_operations(t_env *e)
{
	int		bpp;
	int		size_line;
	int		endian;

	e->image = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img_data = mlx_get_data_addr(e->image, &bpp, &size_line, &endian);
	draw_map(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->image, e->left, e->up);
	mlx_destroy_image(e->mlx, e->image);
	display_hud(e);
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
	e->scale = 1;
	e->left = 0;
	e->up = 0;
	e->z_scale = 0;
	if (!(e->mlx = mlx_init()))
		return (0);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "behamon - fdf");
	mlx_key_hook(e->win, kill_win, e);
	mlx_hook(e->win, 2, 3, fdf_mouvement, e);
	mlx_loop_hook(e->mlx, image_operations, e);
	mlx_loop(e->mlx);
	return (0);
}

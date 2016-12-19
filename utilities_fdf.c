/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:45:58 by behamon           #+#    #+#             */
/*   Updated: 2016/12/10 00:11:09 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		kill_win(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 71)
		mlx_clear_window(env->mlx, env->win);
	return (0);
}

int		fdf_mouvement(int keycode, t_env *e)
{
	if (keycode == 69 || keycode == 24)
	{
		e->scale = e->scale + 1;
		e->z_scale = e->z_scale + 0.1;
	}
	if (keycode == 78 || keycode == 27)
	{
		e->scale = e->scale - 1;
		e->z_scale = e->z_scale - 0.1;
	}
	if (keycode == 31)
		e->z_scale += 1;
	if (keycode == 34)
		e->z_scale -= 1;
	if (keycode == 13 || keycode == 126)
		e->up -= 5;
	if (keycode == 1 || keycode == 125)
		e->up += 5;
	if (keycode == 0 || keycode == 123)
		e->left -= 5;
	if (keycode == 2 || keycode == 124)
		e->left += 5;
	return (0);
}

void	put_pixel_to_image(int x, int y, t_env *e, int color)
{
	if ((x > 0 && y > 0) && (x <= WIDTH && y <= HEIGHT) && color == 1)
	{
		e->img_data[(x * 4) + (y * WIDTH * 4) + 1] = 0;
		e->img_data[(x * 4) + (y * WIDTH * 4) + 2] = 0;
		e->img_data[(x * 4) + (y * WIDTH * 4)] = 204;
	}
	else if ((x > 0 && y > 0) && (x <= WIDTH && y <= HEIGHT) && color == 2)
	{
		e->img_data[(x * 4) + (y * WIDTH * 4) + 2] = 15;
		e->img_data[(x * 4) + (y * WIDTH * 4) + 1] = 155;
		e->img_data[(x * 4) + (y * WIDTH * 4)] = 0;
	}
	else if ((x > 0 && y > 0) && (x <= WIDTH && y <= HEIGHT) && color == 3)
	{
		e->img_data[(x * 4) + (y * WIDTH * 4) + 2] = 81;
		e->img_data[(x * 4) + (y * WIDTH * 4) + 1] = 62;
		e->img_data[(x * 4) + (y * WIDTH * 4)] = 17;
	}
	else if ((x > 0 && y > 0) && (x <= WIDTH && y <= HEIGHT) && color == 4)
	{
		e->img_data[(x * 4) + (y * WIDTH * 4) + 1] = 250;
		e->img_data[(x * 4) + (y * WIDTH * 4) + 2] = 242;
		e->img_data[(x * 4) + (y * WIDTH * 4)] = 224;
	}
}

int		get_color(t_env *e, int x, int y)
{
	if (e->map[y][x] <= 0)
		return (1);
	else if (e->map[y][x] > 0 && e->map[y][x] <= 30)
		return (2);
	else if (e->map[y][x] >= 31 && e->map[y][x] <= 110)
		return (3);
	else
		return (4);
}

size_t	x_len(int **map, size_t y_max)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (map[i][j] != TAB_STOP)
		j++;
	len = j;
	j = 0;
	while (i < y_max - 1)
	{
		while (map[i][j] != TAB_STOP)
			j++;
		if (j != len)
			return (0);
		j = 0;
		i++;
	}
	return (len);
}

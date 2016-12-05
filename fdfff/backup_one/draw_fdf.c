/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:16:52 by behamon           #+#    #+#             */
/*   Updated: 2016/11/30 19:13:03 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		draw_line(t_env *env)
{
	double	dx;
	double	dy;
	double	temp;
	double	x1;
	double	y1;

	x1 = env->x1;
	y1 = env->y1;
	dx = env->x2 - x1;
	dy = env->y2 - y1;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		put_pixel_to_image(x1, y1, env);
		x1 += dx;
		y1 += dy;
		temp--;
	}
	return (0);
}

void	draw_map(t_env *env)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < env->y_max - 1)
	{
		env->x1 = WIDTH / 3;
		env->x2 = WIDTH / 3;
		while (env->map[i][j + 1] != TAB_STOP)
		{
			if (i == env->y_max - 2)
			{
				env->y1 += SCALE;
				env->y2 = env->y1;
				env->x2 += SCALE;
				draw_line(env);
				env->x2 -= SCALE;
				env->y1 -= SCALE;
				env->y2 -= SCALE;
			}
			env->y2 += SCALE;
			draw_line(env);
			env->y2 -= SCALE;
			env->x2 += SCALE;
			draw_line(env);
			env->x1 += SCALE;
			if (env->map[i][j + 2] == TAB_STOP)
			{
				env->y2 += SCALE;
				draw_line(env);
				env->y2 -= SCALE;
			}
			j++;
		}
		env->y1 += SCALE;
		env->y2 += SCALE;
		j = 0;
		i++;
	}
	env->y1 = HEIGHT / 3;
	env->y2 = HEIGHT / 3;
}

int		image_operations(t_env *env)
{
	int		bpp;
	int		size_line;
	int		endian;

	env->image = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_data = mlx_get_data_addr(env->image, &bpp, &size_line, &endian);
	draw_map(env);
	mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
	mlx_destroy_image(env->mlx, env->image);
	return (0);
}

int		fdf_init(int **map, size_t y_max)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	env->map = map;
	env->y_max = y_max;
	env->y1 = HEIGHT / 3;
	env->y2 = HEIGHT / 3;
	if (!(env->mlx = mlx_init()))
		return (0);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "behamon - fdf");
	mlx_key_hook(env->win, kill_win, env);
	mlx_loop_hook(env->mlx, image_operations, env);
	mlx_loop(env->mlx);
	return (0);
}

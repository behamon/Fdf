/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:16:52 by behamon           #+#    #+#             */
/*   Updated: 2016/11/30 11:00:05 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		kill_win(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 71)
		mlx_clear_window(env->mlx, env->win);
	return (0);
}

void	put_pixel_to_image(int x, int y, t_env *env)
{
	if ((x > 0 && y > 0) && (x <= WIDTH && y <= HEIGHT))
	{
		env->img_data[(x * 4) + (y * WIDTH * 4)] = 255;
		env->img_data[(x * 4) + (y * WIDTH * 4) + 1] = 255;
		env->img_data[(x * 4) + (y * WIDTH * 4) + 2] = 255;
	}
}

int		draw(int xb, int yb, t_env *env)
{
	double  dx;
	double  dy;
	double  x;
	double  y;
	double  temp;

	x = (double)env->x1;
	y = (double)env->y1;
	dx = xb - env->x1;
	dy = yb - env->y1;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x0FFFFFF);
		x += dx;
		y += dy;
		temp -= 1;
	}
	env->x1 = xb;
	env->y1 = yb;
	return (0);
}


int		main()
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	env->x1 = WIDTH / 2;
	env->y1 = HEIGHT / 2;

	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "bg");
	//	env->image = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	mlx_hook(env->win, 6, (1L<<6), draw, env);
	mlx_key_hook(env->win, kill_win, env);
	mlx_loop(env->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:27:30 by behamon           #+#    #+#             */
/*   Updated: 2016/12/05 18:47:10 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_hud(t_env *e)
{
	char *str;
	char *str2;

	str = "Use arrows or wasd keys to move the map";
	str2 = "Press i/o to manage map height";
	mlx_string_put(e->mlx, e->win, 10, 10, 0x0FFFFFF, "Welcome !");
	mlx_string_put(e->mlx, e->win, 10, 40, 0x0FFFFFF, "Press	+/- to zoom");
	mlx_string_put(e->mlx, e->win, 10, 60, 0x0FFFFFF, str2);
	mlx_string_put(e->mlx, e->win, 10, 90, 0x0FFFFFF, str);
	mlx_string_put(e->mlx, e->win, 10, 1050, 0x3399FF, "Current position :");
	mlx_string_put(e->mlx, e->win, 200, 1050, 0x3399FF, ft_itoa(e->left));
	mlx_string_put(e->mlx, e->win, 230, 1050, 0x3399FF, ",");
	mlx_string_put(e->mlx, e->win, 245, 1050, 0x3399FF, ft_itoa(-(e->up)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:46:16 by behamon           #+#    #+#             */
/*   Updated: 2016/12/15 14:57:54 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"

# define WIDTH 2222
# define HEIGHT 1280

# define TAB_STOP 7777777

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*img_data;
	int		**map;
	size_t	x_max;
	size_t	y_max;
	int		scale;
	float	z_scale;
	int		left;
	int		up;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
}				t_env;

int				fdf_init(int **map, size_t n_lines);
int				**fill_int_map(int fd, size_t n_lines);

void			display_hud(t_env *e);

int				kill_win(int keycode, t_env *env);
int				fdf_mouvement(int keycode, t_env *e);
void			put_pixel_to_image(int x, int y, t_env *env, int color);
int				get_color(t_env *e, int x, int y);
size_t			x_len(int **map, size_t y_max);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:46:16 by behamon           #+#    #+#             */
/*   Updated: 2016/12/05 19:03:52 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"

# define ABS(Value) ((Value < 0) ? -Value : Value)

# define WIDTH 1920
# define HEIGHT 1080

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
int				kill_win(int keycode, t_env *env);
int				get_color(t_env *e, int x, int y);
void			put_pixel_to_image(int x, int y, t_env *env, int color);
size_t			x_len(int **map, size_t y_max);
int				fdf_mouvement(int keycode, t_env *e);
void			display_hud(t_env *e);

#endif

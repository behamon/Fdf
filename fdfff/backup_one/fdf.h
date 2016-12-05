/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:46:16 by behamon           #+#    #+#             */
/*   Updated: 2016/11/29 18:50:37 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

# define WIDTH 1280
# define HEIGHT 720

# define TAB_STOP 7777777

# define SCALE 30

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*img_data;
	int		**map;
	size_t	y_max;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
}				t_env;

int				fdf_init(int **map, size_t n_lines);
int				kill_win(int keycode, t_env *env);
void			put_pixel_to_image(int x, int y, t_env *env);


#endif

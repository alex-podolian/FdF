/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:24:21 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/20 20:35:31 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# include "../libft_printf/includes/ft_printf.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vector;

typedef struct	s_map
{
	int			height;
	int			width;
	int			min_depth;
	int			max_depth;
	t_vector	**vector;
}				t_map;

typedef struct	s_line
{
	t_vector	start;
	t_vector	stop;
	int			d_x;
	int			d_y;
	int			s_x;
	int			s_y;
	int			error;
	int			error_2;
}

typedef struct	s_img
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			stride;
	int			end;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_img		*img;
	t_cam		*cam;
	t_mouse		*mouse;
	double		**zbuf;
}				t_mlx;

int				ft_validate_map(int fd, t_map **m);
void			ft_depth(t_map *m);
void			ft_colors(t_map *m);
t_img			*ft_make_image(t_mlx *mlx);
t_img			*ft_img_del(t_mlx *mlx, t_img *img);
void			ft_rendering(t_mlx *mlx);

#endif

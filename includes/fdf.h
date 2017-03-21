/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:24:21 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/21 18:04:28 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# include "../libft_printf/includes/ft_printf.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <limits.h>

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
	int			err;
	int			err_2;
}				t_line;

typedef struct	s_img
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			stride;
	int			end;
}				t_img;

typedef struct	s_cam
{
	double		x;
	double		y;
	double		offset_x;
	double		offset_y;
	int			scale;
	double		**matrix;
}				t_cam;

typedef struct	s_mouse
{
	int			x;
	int			y;
	int			last_x;
	int			last_y;
	char		down;
}				t_mouse;

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
t_img			*ft_make_img(t_mlx *mlx);
t_img			*ft_img_del(t_mlx *mlx, t_img *img);
void			ft_rendering(t_mlx *mlx);
void			ft_line(t_mlx *mlx, t_vector v_1, t_vector v_2);
double			ft_point(double val, double min, double max);
void			ft_set_pixel(t_img *img, int x, int y, int color);
int				ft_get_color(int c_1, int c_2, double p);
int				ft_key_esc(int key, t_mlx *mlx);
int				ft_mouse_down(int button, int x, int y, t_mlx *mlx);
int				ft_mouse_up(int button, int x, int y, t_mlx *mlx);
int				ft_mouse_move(int x, int y, t_mlx *mlx);

#endif

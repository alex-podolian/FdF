/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:44:02 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/21 16:54:09 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vector	ft_vector(t_vector v, t_mlx *mlx)
{
	v.x -= (double)(mlx->map->width - 1) / 2.0f;
	v.y -= (double)(mlx->map->height - 1) / 2.0f;
	v.z -= (double)(mlx->map->min_depth + mlx->map->max_depth) / 2.0f;
	v = ft_rotation(v, mlx->cam);
	v.x *= mlx->cam->scale;
	v.y *= mlx->cam->scale;
	v.x += mlx->cam->offset_x;
	v.y += mlx->cam->offset_y;
	return (v);
}

static t_vector	ft_position(t_map *map, int x, int y)
{
	return (*map->vector[y * map->width + x]);
}

void			ft_rendering(t_mlx *mlx)
{
	t_map		*map;
	int			x;
	int			y;
	t_vector	v;

	map = mlx->map;
	ft_bzero(mlx->img->ptr, WIN_WIDTH * WIN_HEIGHT * mlx->img->bpp);
	x = -1;
	while (++x < map->width)
	{
		y = -1;
		while (++y < map->height)
		{
			v = ft_vector(ft_position(map, x, y), mlx);
			if (x + 1 < map->width)
				ft_line(mlx, v, ft_vector(ft_position(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				ft_line(mlx, v, ft_vector(ft_position(map, x, y + 1), mlx));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 0, 0);
}

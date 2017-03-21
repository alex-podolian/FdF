/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:56:17 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/21 15:46:57 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx	*ft_mlx_del(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->img)
		ft_img_del(mlx, mlx->img);
	if (mlx->cam)
		ft_memdel((void **)&mlx->cam);
	if (mlx->mouse)
		ft_memdel((void **)&mlx->mouse);
	ft_memdel((void **)&mlx);
	return (0);
}

static t_mlx	*ft_init(char *title)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (0);
	if (!(mlx->mlx = mlx_init()) ||
		!(mlx->img = ft_make_img(mlx)) ||
		!(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, title))
		|| !(mlx->cam = ft_memalloc(sizeof(t_cam)))
		|| !(mlx->mouse = ft_memalloc(sizeof(t_mouse))))
		return (ft_mlx_del(mlx));
	mlx->cam->x = 0.5;
	mlx->cam->y = 0.5;
	mlx->cam->scale = 32;
	mlx->cam->offset_x = WIN_WIDTH / 2;
	mlx->cam->offset_y = WIN_HEIGHT / 2;
	return (mlx);
}

static int		ft_error(char *str)
{
	ft_putstr(str);
	return (1);
}

int				main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_mlx	*mlx;

	if (argc != 2)
		return (ft_error("usage: ./fdf source_file\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !ft_validate_map(fd, &map))
		return (ft_error("error: invalid file\n"));
	if (!(mlx = ft_init(ft_strjoin("FdF - ", argv[1]))))
		return (ft_error("error: mlx couldn't init"));
	mlx->map = map;
	ft_rendering(mlx);
	return (0);
}

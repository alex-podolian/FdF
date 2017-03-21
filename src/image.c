/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:44:21 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/21 18:08:00 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(img->ptr + ((x + y * WIN_WIDTH) * img->bpp)) = color;
}

t_img		*ft_img_del(t_mlx *mlx, t_img *img)
{
	if (img)
	{
		if (img->img)
			mlx_destroy_image(mlx->mlx, img->img);
		ft_memdel((void **)&img);
	}
	return (0);
}

t_img		*ft_make_img(t_mlx *mlx)
{
	t_img	*img;

	if (!(img = ft_memalloc(sizeof(t_img))))
		return (0);
	if (!(img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT)))
		return (ft_img_del(mlx, img));
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->stride, &img->end);
	img->bpp /= 8;
	return (img);
}

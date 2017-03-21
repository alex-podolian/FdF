#include "fdf.h"

t_image		*ft_img_del(t_mlx *mlx, t_img *img)
{
	if (img)
	{
		if (img->img)
			mlx_destroy_image(mlx->mlx, img->img);
		ft_memdel((void **)&img);
	}
	return (0);
}

t_image		*ft_make_img(t_mlx *mlx)
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

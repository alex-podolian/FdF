#include "fdf.h"

int		ft_mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->mouse->last_x = mlx->mouse->x;
	mlx->mouse->last_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->down & (1 << 1) && mlx->mouse->down &(1 << 2))
	{
		mlx->cam->offset_x += (x - mlx->mouse->last_x);
		mlx->cam->offset_y += (y - mlx->mouse->last_y);
	}
	else if (mlx->mouse->down & (1 << 1))
	{
		mlx->cam->x += (mlx->mouse->last_y - y) / 200.0f;
		mlx->cam->y -= (mlx->mouse->last_x - x) / 200.0f;
	}
	else if (mlx->mouse->down & (1 << 2))
	{
		mlx->cam->scale += (mlx->mouse->last_y - y) / 10.0f + 0.5f;
		if (mlx->cam->scale < 1)
			mlx->cam->scale = 1;
	}
	if (mlx->mouse->down)
		ft_rendering(mlx);
	return (0);
}
int		ft_mouse_up(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->down &= ~(1 << button);
	return (0);
}

int		ft_mouse_down(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse->down |= 1 << button;
	return (0);
}

int		ft_key_esc(int key, t_mlx *mlx)
{
	(void)mlx;

	if (key = 53)
		exit(EXIT_SUCCESS);
	return (0);
}

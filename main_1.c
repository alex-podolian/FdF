/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:11:46 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/16 17:14:28 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src_printf/ft_printf.h"
#include "minilibx/mlx.h"

/*int		my_key_funct(int keycode, void *mlx, void *win)
{
	ft_printf("key event %d\n", keycode);
	mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
	return (0);
}*/

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 420, 420, "42");
	sleep(2);
	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x <  200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			usleep(500);
			x++;
		}
		y++;
	}
//	mlx_key_hook(win, my_key_funct, mlx);
//	mlx_loop(mlx);
	return (0);
}

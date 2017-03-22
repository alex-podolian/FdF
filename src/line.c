/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:55:27 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/22 19:13:40 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_process_point(t_mlx *mlx, t_line *line, t_vector *v_1,
			t_vector *v_2)
{
	double	prec;

	if (v_1->x < 0 || v_1->x >= WIN_WIDTH || v_1->y < 0 ||
		v_1->y >= WIN_HEIGHT || v_2->x < 0 || v_2->x >= WIN_WIDTH ||
		v_2->y < 0 || v_2->y >= WIN_HEIGHT)
		return (1);
	prec = (line->d_x > line->d_y ?
		ft_point((int)v_1->x, (int)line->start.x, (int)line->stop.x) :
		ft_point((int)v_1->y, (int)line->start.y, (int)line->stop.y));
	ft_set_pixel(mlx->img, (int)v_1->x, (int)v_1->y, ft_get_color(v_1->color,
		v_2->color, prec));
	line->err_2 = line->err;
	if (line->err_2 > -line->d_x)
	{
		line->err -= line->d_y;
		v_1->x += line->s_x;
	}
	if (line->err_2 < line->d_y)
	{
		line->err += line->d_x;
		v_1->y += line->s_y;
	}
	return (0);
}

static void	ft_fix_xy(t_vector *v, t_vector *v_1, t_vector *v_2, int route)
{
	if (route & 1)
	{
		v->x = v_1->x + (v_2->x - v_1->x) * (WIN_HEIGHT - v_1->y) /
			(v_2->y - v_1->y);
		v->y = WIN_HEIGHT - 1;
	}
	else if (route & 2)
	{
		v->x = v_1->x + (v_2->x - v_1->x) * -v_1->y / (v_2->y - v_1->y);
		v->y = 0;
	}
	else if (route & 4)
	{
		v->x = WIN_WIDTH - 1;
		v->y = v_1->y + (v_2->y - v_1->y) * (WIN_WIDTH - v_1->x) /
			(v_2->x - v_1->x);
	}
	else
	{
		v->x = 0;
		v->y = v_1->y + (v_2->y - v_1->y) * -v_1->x / (v_2->x - v_1->x);
	}
}

static int	ft_region(int x, int y)
{
	int		reg;

	reg = 0;
	if (y >= WIN_HEIGHT)
		reg |= 1;
	else if (y < 0)
		reg |= 2;
	if (x >= WIN_WIDTH)
		reg |= 4;
	else if (x < 0)
		reg |= 8;
	return (reg);
}

static int	ft_fix_line(t_vector *v_1, t_vector *v_2)
{
	int			reg_1;
	int			reg_2;
	int			route;
	t_vector	v;

	reg_1 = ft_region(v_1->x, v_1->y);
	reg_2 = ft_region(v_2->x, v_2->y);
	while (!(!(reg_1 | reg_2) || (reg_1 & reg_2)))
	{
		route = reg_1 ? reg_1 : reg_2;
		ft_fix_xy(&v, v_1, v_2, route);
		if (route == reg_1)
		{
			v_1->x = v.x;
			v_1->y = v.y;
			reg_1 = ft_region(v_1->x, v_1->y);
		}
		else
		{
			v_2->x = v.x;
			v_2->y = v.y;
			reg_2 = ft_region(v_2->x, v_2->y);
		}
	}
	return (!(reg_1 | reg_2));
}

void		ft_line(t_mlx *mlx, t_vector v_1, t_vector v_2)
{
	t_line	line;

	v_1.x = (int)v_1.x;
	v_2.x = (int)v_2.x;
	v_1.y = (int)v_1.y;
	v_2.y = (int)v_2.y;
	line.start = v_1;
	line.stop = v_2;
	if (!ft_fix_line(&v_1, &v_2))
		return ;
	line.d_x = (int)ABS((int)v_2.x - (int)v_1.x);
	line.d_y = (int)ABS((int)v_2.y - (int)v_1.y);
	line.s_x = (int)v_1.x < (int)v_2.x ? 1 : -1;
	line.s_y = (int)v_1.y < (int)v_2.y ? 1 : -1;
	line.err = (line.d_x > line.d_y ? line.d_x : -line.d_y) / 2;
	while (((int)v_1.x != (int)v_2.x || (int)v_1.y != (int)v_2.y))
		if (ft_process_point(mlx, &line, &v_1, &v_2))
			break ;
}
